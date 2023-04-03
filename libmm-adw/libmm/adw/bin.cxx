// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/bin.hxx>
#include <libmm/adw/bin_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwBin* object, bool take_copy) -> Adw::Bin*
  {
    return dynamic_cast<Adw::Bin*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Bin_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Bin_Class::class_init_function;

      register_derived_type (adw_bin_get_type ());
    }

    return *this;
  }

  auto
  Bin_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Bin_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Bin ((AdwBin*) (o)));
  }

  Bin::Bin (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Bin::Bin (AdwBin* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Bin::Bin (Bin&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Bin::operator= (Bin&& src) noexcept -> Bin&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Bin::~Bin () noexcept
  {
    destroy_ ();
  }

  Bin::CppClassType Bin::bin_class_;

  auto
  Bin::get_type () -> GType
  {
    return bin_class_.init ().get_type ();
  }

  auto
  Bin::get_base_type () -> GType
  {
    return adw_bin_get_type ();
  }

  Bin::Bin ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (bin_class_.init ()))
  {
  }

  auto
  Bin::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_bin_get_child (const_cast<AdwBin*> (gobj ())));
  }

  auto
  Bin::set_child (Gtk::Widget* widget) -> void
  {
    adw_bin_set_child (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  Bin::property_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "child");
  }

  auto
  Bin::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

} // namespace Adw
