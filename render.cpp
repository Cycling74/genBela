#include <Bela.h>
#include "gen_export.h"

CommonState* gState = NULL;
t_sample* gInputs = NULL;
t_sample* gOutputs = NULL;

bool setup(BelaContext *context, void *userData)
{
	gState = (CommonState*)gen_export::create(context->audioSampleRate, context->audioFrames);
	gInputs = new t_sample[context->audioFrames * context->audioInChannels];
	gOutputs = new t_sample[context->audioFrames * context->audioOutChannels];
	return true;
}

void render(BelaContext *context, void *userData)
{
	int nFrames = context->audioFrames;

	int nInChannels = context->audioInChannels;
	t_sample* ip[nInChannels];
	for (int i = 0; i < nInChannels; i++) {
		for (int j = 0; j < nFrames; j++) {
			*(gInputs + ((i * nFrames) + j)) = audioRead(context, j, i);
		}
		ip[i] = gInputs + (i * nFrames);
	}

	int nOutChannels = context->audioOutChannels;
	t_sample* op[nOutChannels];
	for (int i = 0; i < nOutChannels; i++) {
		op[i] = gOutputs + (i * nFrames);
	}

	gen_export::perform(gState, ip, nInChannels, op, nOutChannels, nFrames);

	for (int i = 0; i < nOutChannels; i++) {
		for (int j = 0; j < nFrames; j++) {
			audioWrite(context, j, i, *(gOutputs + ((i * nFrames) + j)));
		}
	}
}

void cleanup(BelaContext *context, void *userData)
{
    if (gState) {
        gen_export::destroy(gState);
    }
		if (gInputs) {
			delete[] gInputs;
		}
		if (gOutputs) {
			delete[] gOutputs;
		}
}
