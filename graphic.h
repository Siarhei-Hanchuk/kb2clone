void gui_bkdlg_show(cairo_t *cr);
void gui_dialog_show(const gchar *head, const gchar *msg);
void gui_draw_image_cst(cairo_t *cr,cairo_surface_t *cst, int x, int y);
void gui_draw_point(cairo_t* cr,gint16 x,gint16 y, gint16 size,double red, double green, double blue);
void gui_draw_line(cairo_t* cr,gint16 x,gint16 y, gint16 X,gint16 Y, gint16 size,double red, double green, double blue);
void gui_textsid_print(cairo_t *cr, const gchar *sid,gint x, gint y);
void gui_text_print(cairo_t *cr, const gchar *s,gint x, gint y);

