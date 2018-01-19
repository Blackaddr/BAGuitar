/*
 * AudioEffectAnalogDelay.h
 *
 *  Created on: Jan 7, 2018
 *      Author: slascos
 */

#ifndef SRC_AUDIOEFFECTANALOGDELAY_H_
#define SRC_AUDIOEFFECTANALOGDELAY_H_

//#include <vector>

#include <Audio.h>
#include "LibBasicFunctions.h"

namespace BAGuitar {

class AudioEffectAnalogDelay : public AudioStream {
public:
	static constexpr int MAX_DELAY_CHANNELS = 8;

	AudioEffectAnalogDelay() = delete;
	AudioEffectAnalogDelay(float maxDelay);
	AudioEffectAnalogDelay(size_t numSamples);
	AudioEffectAnalogDelay(ExtMemSlot *slot); // requires sufficiently sized pre-allocated memory
	virtual ~AudioEffectAnalogDelay();

	virtual void update(void);
	void delay(float milliseconds);
	void delay(size_t delaySamples);
	void feedback(float feedback) { m_feedback = feedback; }
	void mix(float mix) { m_mix = mix; }
	void enable() { m_enable = true; }
	void disable() { m_enable = false; }

private:
	audio_block_t *m_inputQueueArray[1];
	bool m_enable = false;
	bool m_externalMemory = false;
	AudioDelay *m_memory = nullptr;

	size_t m_delaySamples = 0;
	float m_feedback = 0.0f;
	float m_mix = 0.0f;

	size_t m_callCount = 0;

	audio_block_t *m_previousBlock = nullptr;
	void m_preProcessing(audio_block_t *out, audio_block_t *dry, audio_block_t *wet);
	void m_postProcessing(audio_block_t *out, audio_block_t *dry, audio_block_t *wet);
};

}

#endif /* SRC_AUDIOEFFECTANALOGDELAY_H_ */
