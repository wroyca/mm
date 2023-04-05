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
  class LIBMM_ADW_SYMEXPORT LeafletPage_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT LeafletPage : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = LeafletPage;
    using CppClassType = LeafletPage_Class;
    using BaseObjectType = AdwLeafletPage;
    using BaseClassType = AdwLeafletPageClass;

    LeafletPage (const LeafletPage&) = delete;
    auto
    operator= (const LeafletPage&) -> LeafletPage& = delete;

  private:
    friend class LeafletPage_Class;
    static CppClassType leafletpage_class_;

  protected:
    explicit LeafletPage (const glib::ConstructParams& construct_params);
    explicit LeafletPage (AdwLeafletPage* castitem);

#endif

  public:
    LeafletPage (LeafletPage&& src) noexcept;
    auto
    operator= (LeafletPage&& src) noexcept -> LeafletPage&;

    ~LeafletPage () noexcept override;

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
    LeafletPage ();

  public:
    static auto
    create () -> glib::RefPtr<LeafletPage>;

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
  wrap (AdwLeafletPage* object, bool take_copy = false) -> glib::RefPtr<adw::LeafletPage>;
}

#endif
