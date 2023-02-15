// SPDX-License-Identifier: LGPL-2.1-or-later

#include <sstream>
#include <stdexcept>

#include <libmm-adw/mm-adw.hxx>
#include <libmm-adw/version.hxx>

#undef NDEBUG
#include <cassert>

auto
main () -> int
{
  using namespace std;
  using namespace mm_adw;

  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  try
  {
    ostringstream o;
    say_hello (o, "");
    assert (false);
  }
  catch (const invalid_argument& e)
  {
    assert (e.what () == string ("empty name"));
  }
}
