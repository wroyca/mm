// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SQUEEZERPAGE_H
#define _LIBADWAITAMM_SQUEEZERPAGE_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT SqueezerPage_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT SqueezerPage : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SqueezerPage;
    using CppClassType = SqueezerPage_Class;
    using BaseObjectType = AdwSqueezerPage;
    using BaseClassType = AdwSqueezerPageClass;

    SqueezerPage (const SqueezerPage&) = delete;
    auto
    operator= (const SqueezerPage&) -> SqueezerPage& = delete;

  private:
    friend class SqueezerPage_Class;
    static CppClassType squeezerpage_class_;

  protected:
    explicit SqueezerPage (const glib::ConstructParams& construct_params);
    explicit SqueezerPage (AdwSqueezerPage* castitem);

#endif

  public:
    SqueezerPage (SqueezerPage&& src) noexcept;
    auto
    operator= (SqueezerPage&& src) noexcept -> SqueezerPage&;

    ~SqueezerPage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwSqueezerPage*
    {
      return reinterpret_cast<AdwSqueezerPage*> (gobject_);
    }

    auto
    gobj () const -> const AdwSqueezerPage*
    {
      return reinterpret_cast<AdwSqueezerPage*> (gobject_);
    }

    auto
    gobj_copy () -> AdwSqueezerPage*;

  private:
  protected:
    SqueezerPage ();

  public:
    static auto
    create () -> glib::RefPtr<SqueezerPage>;

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_enabled () const -> bool;

    auto
    set_enabled (bool enabled) -> void;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_enabled () -> glib::PropertyProxy<bool>;

    auto
    property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwSqueezerPage* object, bool take_copy = false) -> glib::RefPtr<adw::SqueezerPage>;
}

#endif
