
#include "cookbookogl.h"
#include <string>

class Texture {
public:
    static GLuint loadTexture( GLubyte*, int, int );
    static GLuint loadCubeMap( const std::string & baseName );
    static unsigned char * loadPixels( const std::string & fName, int & w, int & h );
};