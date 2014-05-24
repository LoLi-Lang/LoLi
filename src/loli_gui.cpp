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

#include <gtkmm.h>

int guitest(int argc, char *argv[]){
	Glib::RefPtr<Gtk::Application> test =
		Gtk::Application::create(argc, argv, "org.zshang.loli.test");
	Gtk::Window win;
	win.set_default_size(200, 200);

	return test->run(win);
}
