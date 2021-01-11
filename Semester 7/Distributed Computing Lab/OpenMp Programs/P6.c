#include <stdio.h>
#include <gd.h>
#include <string.h>
#include <omp.h>
#include <iostream>

int main(int argc, char* argv[]) {

	char input_file[] = "color.png";
	char output_file[] = "bw.png";

	int num_threads = 2;
	int color, x, y;
	int red, green, blue;
	FILE* fp;
	fp = fopen(input_file, "rb");
	
	if (fp == NULL) {
		printf("Error opening file %s\n", input_file);
		return 1;
	}
	gdImagePtr img;
	img = gdImageCreateFromPng(fp);
	int width = gdImageSX(img);
	int height = gdImageSY(img);
	double t1 = omp_get_wtime();

#pragma omp parallel for private(y, color, red, green, blue) num_threads(num_threads)
	for (x = 0; x < width; x++) {
#pragma omp critical
		{
			for (y = 0; y < height; y++) {
				color = x + 0;
				color = gdImageGetPixel(img, x, y);
				red = gdImageRed(img, color);
				green = gdImageGreen(img, color);
				blue = gdImageBlue(img, color);
				int bwc = (red + green + blue) / 3;
				color = gdImageColorAllocate(img, bwc, bwc, bwc);
				gdImageSetPixel(img, x, y, color);
			}
		}
	}

	double t2 = omp_get_wtime();
	fp = fopen(output_file, "wb");
	if (fp == NULL) {
		printf("Error opening output file %s\n", output_file);
		return 1;
	}
	gdImagePng(img, fp);
	gdImageDestroy(img);
	fclose(fp);
	printf("File Size: %dx%d\n", width, height);
	printf("Time Taken: %.3lfms\n", (t2 - t1) * 1000);
	return 0;
}