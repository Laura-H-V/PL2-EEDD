#include "NodoPila.h"

NodoPila::NodoPila() : valor(Proceso()), siguiente(nullptr) {}

NodoPila::NodoPila(Proceso v, NodoPila *sig) : valor(v), siguiente(sig) {}

NodoPila::~NodoPila() {} // Destructor vacío
