#include "header.h"
#include "texts.h"

void gui_bkdlg_show(cairo_t *cr)
{
    cairo_move_to(cr,0,screenh-125);
    cairo_set_source_rgb(cr, 0,0,0);
    cairo_set_line_width (cr,250);
    cairo_line_to(cr,screenw-160,screenh-125);
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 255/255, 255/255, 255/255);
    cairo_set_line_width (cr, 4);

    cairo_move_to(cr,2,screenh-125*2);
    cairo_line_to(cr,2,screenh);
    cairo_move_to(cr,0,screenh);
    cairo_line_to(cr,screenw-160,screenh);
    cairo_move_to(cr,screenw-160-2,screenh);
    cairo_line_to(cr,screenw-160-2,screenh-125*2);
    cairo_move_to(cr,screenw-160-2,screenh-125*2);
    cairo_line_to(cr,2,screenh-125*2);

    cairo_stroke(cr);
}

/*void gui_draw_image_form_file(cairo_t *cr,const gchar *path, int x, int y)
{
    cairo_surface_t *  cst=cairo_image_surface_create_from_png(path);
    cairo_set_source_surface(cr, cst, x, y);
    cairo_paint (cr);
    cairo_surface_destroy(cst);
}*/

void gui_draw_image_cst(cairo_t *cr,cairo_surface_t *cst, int x, int y)
{
    cairo_set_source_surface(cr, cst, x, y);
    cairo_paint (cr);
}

void gui_draw_point(cairo_t* cr,gint16 x,gint16 y, gint16 size,double red, double green, double blue)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb(cr, red/255,green/255, blue/255);
    cairo_set_line_width (cr, size);
    cairo_line_to(cr,x+size,y);
    cairo_stroke(cr);
}

void gui_draw_line(cairo_t* cr,gint16 x,gint16 y, gint16 X,gint16 Y, gint16 size,double red, double green, double blue)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb(cr, red/255,green/255, blue/255);
    cairo_set_line_width (cr, size);
    cairo_line_to(cr,X,Y);
    cairo_stroke(cr);
}

void gui_textsid_print(cairo_t *cr, const gchar *sid,gint x, gint y)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
    gchar *s=text_get_strid(sid);
    cairo_show_text(cr,s);
    free(s);
}

void gui_text_print(cairo_t *cr, const gchar *s,gint x, gint y)
{
    cairo_move_to(cr,x,y);
    cairo_set_source_rgb (cr, 255, 255, 200);
    cairo_set_font_size(cr, 19);
    cairo_show_text(cr,s);
}
