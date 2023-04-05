// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/scrollbar.hxx>
#include <libmm/gtk/scrollbar_p.hxx>

#include <libmm/gtk/adjustment.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  Scrollbar::Scrollbar (const glib::RefPtr<Adjustment>& adjustment,
                        Orientation orientation)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (scrollbar_class_.init (),
                                          "adjustment",
                                          glib::unwrap (adjustment),
                                          "orientation",
                                          (GtkOrientation) orientation,
                                          nullptr))
  {
  }

  auto
  Scrollbar::unset_adjustment () -> void
  {
    gtk_scrollbar_set_adjustment (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkScrollbar* object, bool take_copy) -> gtk::Scrollbar*
  {
    return dynamic_cast<gtk::Scrollbar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Scrollbar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Scrollbar_Class::class_init_function;

      register_derived_type (gtk_scrollbar_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Scrollbar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Scrollbar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Scrollbar ((GtkScrollbar*) (o)));
  }

  Scrollbar::Scrollbar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Scrollbar::Scrollbar (GtkScrollbar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Scrollbar::Scrollbar (Scrollbar&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Scrollbar::operator= (Scrollbar&& src) noexcept -> Scrollbar&
  {
    gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Scrollbar::~Scrollbar () noexcept
  {
    destroy_ ();
  }

  Scrollbar::CppClassType Scrollbar::scrollbar_class_;

  auto
  Scrollbar::get_type () -> GType
  {
    return scrollbar_class_.init ().get_type ();
  }

  auto
  Scrollbar::get_base_type () -> GType
  {
    return gtk_scrollbar_get_type ();
  }

  Scrollbar::Scrollbar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (scrollbar_class_.init ()))
  {
  }

  auto
  Scrollbar::set_adjustment (const glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_scrollbar_set_adjustment (gobj (), glib::unwrap (adjustment));
  }

  auto
  Scrollbar::get_adjustment () -> glib::RefPtr<Adjustment>
  {
    auto retvalue = glib::wrap (gtk_scrollbar_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollbar::get_adjustment () const -> glib::RefPtr<const Adjustment>
  {
    return const_cast<Scrollbar*> (this)->get_adjustment ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Adjustment>>::value,
      "Type glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Scrollbar::property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy<glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  Scrollbar::property_adjustment () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

} // namespace gtk
