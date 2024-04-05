#ifndef PIXEL
#define PIXEL

class Pixel
{
private:

public:

    // Color
    unsigned char R;
    unsigned char G;
    unsigned char B;

    // For intermediate calculations
    bool IsIncluded;

    Pixel()
     : R(255)
     , G(255)
     , B(255)
     , IsIncluded(false)
    {
    }

    Pixel(char r, char g, char b)
	      : R(r)
	      , G(g)
	      , B(b)
    {
    }

};

#endif // PIXEL
