
#include <iostream>

int main()
{
    // writing an simple image in ppm format:
    int image_width = 256;
    int image_height = 256;

    // render 
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; ++j)
    {
        // progress info
        std::clog << "\r Scan-lines remaining :" << (image_height - j) << std::flush;
        for (int i = 0; i < image_width; i++)
        {
            double r = double(i) / (image_width - 1);
            double g = double(j) / (image_height - 1);
            double b = 0.0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }
}