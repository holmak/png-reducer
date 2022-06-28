#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define USE_NEW_NAME 0

int main(int argc, char *argv[])
{
	++argv;
	char *suffix = USE_NEW_NAME ? ".new" : "";
	
	for (;;)
	{
		char *filename = *argv++;
		if (!filename) break;

		int x, y, n;
		char *data = stbi_load(filename, &x, &y, &n, 0);
		if (data)
		{
			char newname[500];
			sprintf(newname, "%s%s", filename, suffix);
			if (!stbi_write_png(newname, x, y, n, data, 0))
			{
				fprintf(stderr, "error: cannot write file data: %s\n", filename);
			}
			stbi_image_free(data);
		}
		else
		{
			fprintf(stderr, "error: cannot read file: %s\n", filename);
		}
	}
}
