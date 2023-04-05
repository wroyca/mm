// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filter.hxx>
#include <libmm/gtk/filter_p.hxx>

#include <gtk/gtk.h>

using Change = gtk::Filter::Change;
using Match = gtk::Filter::Match;

namespace
{

  static auto
  Filter_signal_changed_callback (GtkFilter* self,
                                  GtkFilterChange p0,
                                  void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Change)>;

    auto obj = dynamic_cast<Filter*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<Change> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Filter_signal_changed_info = {
      "changed",
      (GCallback) &Filter_signal_changed_callback,
      (GCallback) &Filter_signal_changed_callback};

} // namespace

auto
glib::Value<gtk::Filter::Match>::value_type () -> GType
{
  return gtk_filter_match_get_type ();
}

auto
glib::Value<gtk::Filter::Change>::value_type () -> GType
{
  return gtk_filter_change_get_type ();
}

namespace glib
{

  auto
  wrap (GtkFilter* object, bool take_copy) -> glib::RefPtr<gtk::Filter>
  {
    return glib::make_refptr_for_instance<gtk::Filter> (
        dynamic_cast<gtk::Filter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Filter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Filter_Class::class_init_function;

      register_derived_type (gtk_filter_get_type ());
    }

    return *this;
  }

  auto
  Filter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->match = &match_vfunc_callback;
    klass->get_strictness = &get_strictness_vfunc_callback;
  }

  auto
  Filter_Class::match_vfunc_callback (GtkFilter* self, gpointer item) -> gboolean
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (
              obj->match_vfunc (glib::wrap (G_OBJECT (item), true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->match)
      return (*base->match) (self, item);

    using RType = gboolean;
    return RType ();
  }

  auto
  Filter_Class::get_strictness_vfunc_callback (GtkFilter* self) -> GtkFilterMatch
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<GtkFilterMatch> (obj->get_strictness_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_strictness)
      return (*base->get_strictness) (self);

    using RType = GtkFilterMatch;
    return RType ();
  }

  auto
  Filter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Filter ((GtkFilter*) object);
  }

  auto
  Filter::gobj_copy () -> GtkFilter*
  {
    reference ();
    return gobj ();
  }

  Filter::Filter (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Filter::Filter (GtkFilter* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Filter::Filter (Filter&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Filter::operator= (Filter&& src) noexcept -> Filter&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Filter::~Filter () noexcept {}

  Filter::CppClassType Filter::filter_class_;

  auto
  Filter::get_type () -> GType
  {
    return filter_class_.init ().get_type ();
  }

  auto
  Filter::get_base_type () -> GType
  {
    return gtk_filter_get_type ();
  }

  Filter::Filter ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (filter_class_.init ()))
  {
  }

  auto
  Filter::match (const glib::RefPtr<glib::ObjectBase>& item) -> bool
  {
    return gtk_filter_match (gobj (), (item)->gobj ());
  }

  auto
  Filter::get_strictness () -> Match
  {
    return static_cast<Match> (gtk_filter_get_strictness (gobj ()));
  }

  auto
  Filter::changed (Change change) -> void
  {
    gtk_filter_changed (gobj (), static_cast<GtkFilterChange> (change));
  }

  auto
  Filter::signal_changed () -> glib::SignalProxy<void (Change)>
  {
    return glib::SignalProxy<void (Change)> (this, &Filter_signal_changed_info);
  }

  auto
  gtk::Filter::match_vfunc (const glib::RefPtr<glib::ObjectBase>& item) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->match)
    {
      bool retval ((*base->match) (gobj (), (item)->gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::Filter::get_strictness_vfunc () -> Match
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_strictness)
    {
      Match retval (static_cast<Match> ((*base->get_strictness) (gobj ())));
      return retval;
    }

    using RType = Match;
    return RType ();
  }

} // namespace gtk
