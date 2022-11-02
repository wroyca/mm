// SPDX-License-Identifier: GPL-3.0-or-later
//

#include <mm/adw/application.hpp>
#include <mm/adw/window.hpp>

class MyWindow : public Adw::Window
{
public:
  MyWindow();
};

MyWindow::MyWindow()
{
  set_title("Basic application");
  set_default_size(900, 900);
}

auto main(const int argc, char *argv[]) -> int
{
  const auto app = Adw::Application::create("org.gtkmm.examples.base");
  return app->make_window_and_run<MyWindow>(argc, argv);
}
