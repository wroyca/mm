#include <sstream>
#include <stdexcept>

#include <libmm-gtk/version.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;
  using namespace mm_gtk;

  // Basics.
  //
  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  // Empty name.
  //
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
