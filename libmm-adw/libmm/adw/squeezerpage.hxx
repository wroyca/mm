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
  class LIBMM_ADW_SYMEXPORT squeezer_page_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT squeezer_page : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = squeezer_page;
    using CppClassType = squeezer_page_class;
    using BaseObjectType = AdwSqueezerPage;
    using BaseClassType = AdwSqueezerPageClass;

    squeezer_page (const squeezer_page&) = delete;
    auto
    operator= (const squeezer_page&) -> squeezer_page& = delete;

  private:
    friend class squeezer_page_class;
    static CppClassType squeezerpage_class_;

  protected:
    explicit squeezer_page (const glib::ConstructParams& construct_params);
    explicit squeezer_page (AdwSqueezerPage* castitem);

#endif

  public:
    squeezer_page (squeezer_page&& src) noexcept;
    auto
    operator= (squeezer_page&& src) noexcept -> squeezer_page&;

    ~squeezer_page () noexcept override;

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
    squeezer_page ();

  public:
    static auto
    create () -> glib::RefPtr<squeezer_page>;

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
  wrap (AdwSqueezerPage* object, bool take_copy = false) -> glib::RefPtr<adw::squeezer_page>;
}

#endif
