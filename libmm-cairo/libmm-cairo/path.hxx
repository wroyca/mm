

#ifndef __CAIROMM_PATH_H
#define __CAIROMM_PATH_H

#include <libmm-cairo/mm-cairoconfig.hxx>

#include <cairo.h>
#include <libmm-cairo/enums.hxx>
#include <string>

namespace Cairo
{

  class CAIROMM_API Path
  {
  public:
    explicit Path (cairo_path_t* cobject, bool take_ownership = false);

    Path (const Path&) = delete;
    auto
    operator= (const Path&) -> Path& = delete;

    virtual ~Path ();

    typedef cairo_path_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

#endif

  protected:
    cobject* m_cobject;
  };

} // namespace Cairo

#endif
