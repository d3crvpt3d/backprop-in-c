#include "../include/neuron.h"

#include <stdlib.h>

//activation functions
float sigmoid(float x){
	return 1/(1+expf(-x));
}

float RELU(float x){
	return fmax(0, x);
}

float leakyRELU(float x){
	if(x >= 0){
		return x;
	}else{
		return x*1e-2;
	}
}

/* FUCNTIONS */
void network_addLayer(network_t *network, uint32_t size, function_t activationFunction){

	network->size++;
	
	layer_t *ptr = realloc(network->layers, sizeof(layer_t) * network->size);

	ptr->size = size;
	ptr->neurons = (neuron_t *) malloc(sizeof(neuron_t) * size);

	for(uint32_t i = 0; i < ptr->size; i++){
		ptr->neurons[i].bias = (((float) rand() / RAND_MAX) * .2f) -.1f;
		ptr->neurons[i].function = activationFunction;
	}
	network->layers = ptr;
}

void network_destroy(network_t *network){
	
	//free each layers neurons
	for(uint32_t a = 0; a < network->size; a++){
		free(network->layers[a].neurons);
	}

	//free layers
	free(network->layers);
}
