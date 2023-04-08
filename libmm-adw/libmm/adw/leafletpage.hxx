// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_LEAFLETPAGE_H
#define _LIBADWAITAMM_LEAFLETPAGE_H

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
  class LIBMM_ADW_SYMEXPORT leaflet_page_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT leaflet_page : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = leaflet_page;
    using CppClassType = leaflet_page_class;
    using BaseObjectType = AdwLeafletPage;
    using BaseClassType = AdwLeafletPageClass;

    leaflet_page (const leaflet_page&) = delete;
    auto
    operator= (const leaflet_page&) -> leaflet_page& = delete;

  private:
    friend class leaflet_page_class;
    static CppClassType leafletpage_class_;

  protected:
    explicit leaflet_page (const glib::ConstructParams& construct_params);
    explicit leaflet_page (AdwLeafletPage* castitem);

#endif

  public:
    leaflet_page (leaflet_page&& src) noexcept;
    auto
    operator= (leaflet_page&& src) noexcept -> leaflet_page&;

    ~leaflet_page () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwLeafletPage*
    {
      return reinterpret_cast<AdwLeafletPage*> (gobject_);
    }

    auto
    gobj () const -> const AdwLeafletPage*
    {
      return reinterpret_cast<AdwLeafletPage*> (gobject_);
    }

    auto
    gobj_copy () -> AdwLeafletPage*;

  private:
  protected:
    leaflet_page ();

  public:
    static auto
    create () -> glib::RefPtr<leaflet_page>;

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_name () const -> glib::ustring;

    auto
    get_navigatable () const -> bool;

    auto
    set_name (const glib::ustring& name) -> void;

    auto
    set_navigatable (bool navigatable) -> void;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_navigatable () -> glib::PropertyProxy<bool>;

    auto
    property_navigatable () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwLeafletPage* object, bool take_copy = false) -> glib::RefPtr<adw::leaflet_page>;
}

#endif
