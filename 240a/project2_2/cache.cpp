#include "cache.h"

/* Fill this in with parameters that will give you the
   best CPI and AMAT. */
void tune_parameters(Core *c) {
	c->setL1Attributes(0, 0, 0);
	c->setVictimAttributes(0, 0, 0);
	c->setL2Attributes(0, 0, 0);
	c->setEvictionPolicy(0);
}

/* Implement this function. 
 * Returns true if there is a cache hit.
 * Arguments: ldst - 0 if load, 1 if store.
 *            address - Memory address of the reference.
 *            cycle - Number of cycles executed so far.
 */
bool Cache::isHit(int ldst, int address, int cycle) {
	return false;
}

/* Implement this function.
 * Returns the number of cycles taken to perform the memory reference.
 * Arguments: ldst - 0 if load, 1 if store.
 *            address - Memory address of the reference.
 *            cycle - Number of cycles executed so far.
 * Function calls you might make: isHit, getters in Cache.
 * Data structures you might need to read and/or update: 
 *           tags and accessed arrays in Cache.
 */
int Core::accessCache(int ldst, int address, int cycles) {
	return 350;
}

/* Implement the following functions. */
double Core::getL1MissRate() {
}
double Core::getVictimLocalMissRate() {
}
double Core::getL2LocalMissRate() {
}
double Core::getL2GlobalMissRate() {
}
