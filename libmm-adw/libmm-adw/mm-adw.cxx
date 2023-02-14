#include <libmm-adw/mm-adw.hxx>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace mm_adw
{
  void
  say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
} // namespace mm_adw
