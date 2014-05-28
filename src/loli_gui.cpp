/*
 * =====================================================================================
 *
 *       Filename:  loli_gui.cpp
 *
 *    Description:  GUI part of LoLi
 *
 *        Version:  1.0
 *        Created:  05/21/2014 11:49:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <gtk/gtk.h>

int guitest(int argc, char *argv[]){
	GtkWidget *window;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	g_signal_connect(GTK_WIDGET(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show(window);
	gtk_main();
	return(0);
}
