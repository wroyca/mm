// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_LEAFLETPAGE_H
#define _LIBADWAITAMM_LEAFLETPAGE_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT LeafletPage_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT LeafletPage : public Glib::Object
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
    explicit LeafletPage (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<LeafletPage>;

    auto
    get_child () const -> Gtk::Widget*;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_navigatable () const -> bool;

    auto
    set_name (const Glib::ustring& name) -> void;

    auto
    set_navigatable (bool navigatable) -> void;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_navigatable () -> Glib::PropertyProxy<bool>;

    auto
    property_navigatable () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwLeafletPage* object, bool take_copy = false) -> Glib::RefPtr<Adw::LeafletPage>;
}

#endif
