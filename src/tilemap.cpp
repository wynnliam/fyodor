// Liam Wynn, 7/31/2020, Fyodor

#include "./tilemap.h"

using namespace fyodor;
using namespace std;

tilemap::tilemap(unsigned int w, unsigned int h, shared_ptr<texture> tex) : width(w), height(h), map_tex(tex) {
}
