/*
 * BAAudioInputI2S.h
 *
 *  Created on: Dec 11, 2017
 *      Author: slascos
 */

#ifndef SRC_BAAUDIOINPUTI2S_H_
#define SRC_BAAUDIOINPUTI2S_H_

#include "Arduino.h"
#include "AudioStream.h"
#include "DMAChannel.h"

namespace BAGuitar {

class BAAudioInputI2S : public AudioStream
{
public:
	//BAAudioInputI2S(void) : AudioStream(0, NULL) { begin(); }
	BAAudioInputI2S(void) : AudioStream(0, NULL) {  }
	virtual void update(void);
	void begin(void);
protected:
	BAAudioInputI2S(int dummy): AudioStream(0, NULL) {} // to be used only inside AudioInputI2Sslave !!
	static bool update_responsibility;
	static DMAChannel dma;
	static void isr(void);
private:
	static audio_block_t *block_left;
	static audio_block_t *block_right;
	static uint16_t block_offset;
};

}

#endif /* SRC_BAAUDIOINPUTI2S_H_ */
