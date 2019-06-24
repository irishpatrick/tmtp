#include "generator.h"

#include <stdio.h>
#include <string.h>
#include <cairo.h>

#include "str_util.h"
#include "ctrl_util.h"

void new_template(const char* in)
{
    char fn[512];
    strncpy(fn, in, 255);
    if (strlen(fn) == 0)
    {
        printf("filename=");
        fgets(fn, 255, stdin);
        fn[strlen(fn)-1] = 0;
        if (!endswith(fn, ".png"))
        {            
            strcat(fn, ".png");
        }
    }

    if (file_exists(fn))
    {
        printf("WARNING! THIS FILE (%s) WILL BE OVERWRITTEN!\n", fn);
        if (!yesno("Continue? (y/n) "))
        {
            return;
        }
    }

    int tile_size;
    int rows;
    int cols;
    int margin;

    printf("tile size=");
    scanf("%d", &tile_size);

    printf("rows=");
    scanf("%d", &rows);
    printf("columns=");
    scanf("%d", &cols);
    printf("margin=");
    scanf("%d", &margin);

    int img_w = (rows * tile_size) + (margin * (rows + 1)) + ((margin / 2) * rows);
    int img_h = (cols * tile_size) + (margin * (cols + 1)) + ((margin / 2) * cols);

    cairo_surface_t* surface;
    cairo_t* cr;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, img_w, img_h);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 255, 0, 255);
    cairo_rectangle(cr, 0, 0, img_w, img_h);
    cairo_fill(cr);

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, margin);

    int i;
    for (i = 0; i < rows + 1; ++i)
    {
        double y = (i * tile_size) + (i * (margin + (margin / 2))) + ((double)(margin) / 2.0);
        cairo_move_to(cr, 0, y);
        cairo_line_to(cr, img_w, y);
    }

    for (i = 0; i < cols + 1; ++i)
    {
        double x = (i * tile_size) + (i * (margin + (margin / 2))) + ((double)(margin) / 2.0);
        cairo_move_to(cr, x, 0);
        cairo_line_to(cr, x, img_h);
    }

    cairo_stroke(cr);

    cairo_surface_write_to_png(surface, fn);

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}

void resize_template(const char* fn)
{
    
}

void scale_template(const char* fn)
{

}