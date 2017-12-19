/*
 * BAAudioOutputI2S.h
 *
 *  Created on: Dec 11, 2017
 *      Author: slascos
 */

#ifndef SRC_BAAUDIOOUTPUTI2S_H_
#define SRC_BAAUDIOOUTPUTI2S_H_


#include "Arduino.h"
#include "AudioStream.h"
#include "DMAChannel.h"

namespace BAGuitar {

class BAAudioOutputI2S : public AudioStream
{
public:
	BAAudioOutputI2S(void) : AudioStream(2, inputQueueArray) { begin(); }
	//BAAudioOutputI2S(void) : AudioStream(2, inputQueueArray) { }
	virtual void update(void);
	void begin(void);
	friend class BAAudioInputI2S;
protected:
	BAAudioOutputI2S(int dummy): AudioStream(2, inputQueueArray) {} // to be used only inside AudioOutputI2Sslave !!
	static void config_i2s(void);
	static audio_block_t *block_left_1st;
	static audio_block_t *block_right_1st;
	static bool update_responsibility;
	static DMAChannel dma;
	static void isr(void);
private:
	static audio_block_t *block_left_2nd;
	static audio_block_t *block_right_2nd;
	static uint16_t block_left_offset;
	static uint16_t block_right_offset;
	audio_block_t *inputQueueArray[2];
};

}

#endif /* SRC_BAAUDIOOUTPUTI2S_H_ */
