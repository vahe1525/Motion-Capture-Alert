
/** Small C++ wrapper around V4L example code to access the webcam
**/

#ifndef WEBCAM_HPP
#define WEBCAM_HPP

// Standart libraries
#include <string>
#include <memory> // unique_ptr

// Project libraries
#include "../Data/Constants.hpp"
#include "Matrix.hpp"
#include "Pixel.hpp"

class Webcam {

struct buffer {
      void   *data;
      size_t  size;
};

struct RGBImage {
      unsigned char   *data; // RGB888 <=> RGB24
      size_t          width;
      size_t          height;
      size_t          size; // width * height * 3
};

public:
    Webcam(const std::string& device = "/dev/video0", 
           int width = CAMERAWIDTH, 
           int height = CAMERAHEIGHT);

    ~Webcam();

    /** Captures and returns a frame from the webcam.
     *
     * The returned object contains a field 'data' with the image data in RGB888
     * format (ie, RGB24), as well as 'width', 'height' and 'size' (equal to
     * width * height * 3)
     *
     * This call blocks until a frame is available or until the provided
     * timeout (in seconds). 
     *
     * Throws a runtime_error if the timeout is reached.
     */
    //const RGBImage& Frame(int timeout = 1);
    std::shared_ptr<Matrix> Frame(int timeout = 1);
private:
    void init_mmap();

    void open_device();
    void close_device();

    void init_device();
    void uninit_device();

    void start_capturing();
    void stop_capturing();

    bool read_frame();

    std::shared_ptr<Matrix> GetMatrixFromFrame(const Webcam::RGBImage& frame);

    std::string device;
    int fd;

    RGBImage rgb_frame;
    struct buffer          *buffers;
    unsigned int     n_buffers;

    size_t xres, yres;
    size_t stride;

    bool force_format = true;
};

#endif // WEBCAM_HPP
