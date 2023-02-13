#include <libmm-gdk/mm-gdk.hxx>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace mm_gdk
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
