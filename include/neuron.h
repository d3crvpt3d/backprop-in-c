#pragma once

#include <stdint.h>
#include <math.h>

/* TYPES */
typedef float (*function_t)(float);

typedef struct {
	float bias;
	function_t function;
} neuron_t;

typedef struct{
	uint32_t size;
	neuron_t *neurons;
} layer_t;

typedef float ** weights_t;

typedef struct{
	uint32_t size;
	layer_t *layers;
} network_t;

/* FUNCTIONS */
void network_addLayer(network_t *network, uint32_t size, function_t activationFunction);

void network_destroy(network_t *network);
