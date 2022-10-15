CC = gcc
GDFLAGS = -lgd -lpng -lz -ljpeg -lfreetype -lm
mandelbroot: CFLAGS = -Wall -I../ -I../../hagl/include -DDISPLAY_WIDTH=640 -DDISPLAY_HEIGHT=480
palette: CFLAGS = -Wall -I../ -I../../hagl/include -DDISPLAY_WIDTH=4080 -DDISPLAY_HEIGHT=4080
hagl_font_test: CFLAGS = -Wall -I../ -I../../hagl/include -I../../embedded-fonts/X11/include/ -I../../embedded-fonts/misc/viznut/include/ -DDISPLAY_WIDTH=640 -DDISPLAY_HEIGHT=480

PALETTEFLAGS =

src = $(wildcard ../*.c) \
      $(wildcard ../../hagl/src/*.c)

obj = $(src:.c=.o)

all: palette mandelbroot

mandelbroot: mandelbroot.c $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(GDFLAGS)

palette: palette.c $(obj)
	$(CC) $(PALETTEFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(GDFLAGS)

hagl_font_test: hagl_font_test.c $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(GDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) mandelbroot palette hagl_font_test *.png *.o
