#include <libmm-cairo/mm-cairo.hxx>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace mm_cairo
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
