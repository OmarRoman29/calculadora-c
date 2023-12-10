#include <gtk/gtk.h>

typedef struct {
  gchar simbolo;
  GtkWidget *btnWid;
} BtnCalc;

typedef struct {
  GtkWidget *win;
  GtkWidget *grid;
  GdkPixbuf *icon;
  BtnCalc numsBtn[10];
  GtkWidget *acBtn;
  GtkWidget *returnBtn;
  BtnCalc divBtn;
  BtnCalc multBtn;
  BtnCalc sumaBtn;
  BtnCalc restaBtn;
  BtnCalc porcentajeBtn;
  BtnCalc igualBtn;
  BtnCalc puntoBtn;
} App;

App app;

BtnCalc crear_btnCalc(gchar simbolo) {
  BtnCalc nuevo;
  char buffer[2] = {simbolo, '\0'};
  nuevo.btnWid = gtk_button_new_with_label(buffer);
  nuevo.simbolo = simbolo;
  return nuevo;
}

// Crea los botones correspondientes del 0 al 9
void init_numsBtn() {
  char i;
  for (i = 0; i < 10; i++)
    app.numsBtn[i] = crear_btnCalc(i + 48);

  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[9].btnWid, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[8].btnWid, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[7].btnWid, 2, 3, 1, 1);

  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[6].btnWid, 0, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[5].btnWid, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[4].btnWid, 2, 4, 1, 1);

  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[3].btnWid, 0, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[2].btnWid, 1, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[1].btnWid, 2, 5, 1, 1);

  gtk_grid_attach(GTK_GRID(app.grid), app.numsBtn[0].btnWid, 0, 6, 2, 1);
}

// Crea los botones correspondientes a operaciones
void init_opBtn() {
  app.acBtn = gtk_button_new_with_label("AC");
  app.returnBtn = gtk_button_new_with_label("<-");
  app.divBtn = crear_btnCalc('/');
  app.multBtn = crear_btnCalc('x');
  app.sumaBtn = crear_btnCalc('+');
  app.restaBtn = crear_btnCalc('-');
  app.porcentajeBtn = crear_btnCalc('%');
  app.igualBtn = crear_btnCalc('=');
  app.puntoBtn = crear_btnCalc('.');

  gtk_grid_attach(GTK_GRID(app.grid), app.acBtn, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.returnBtn, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.porcentajeBtn.btnWid, 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.divBtn.btnWid, 3, 2, 1, 1);

  gtk_grid_attach(GTK_GRID(app.grid), app.multBtn.btnWid, 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.sumaBtn.btnWid, 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.restaBtn.btnWid, 3, 5, 1, 1);

  gtk_grid_attach(GTK_GRID(app.grid), app.igualBtn.btnWid, 3, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(app.grid), app.puntoBtn.btnWid, 2, 6, 1, 1);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  app.win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(G_OBJECT(app.win), "destroy", G_CALLBACK(gtk_main_quit),
                   NULL);

  app.grid = gtk_grid_new();
  init_numsBtn();
  init_opBtn();

  gtk_container_add(GTK_CONTAINER(app.win), app.grid);
  gtk_widget_show_all(app.win);
  gtk_main();
}
