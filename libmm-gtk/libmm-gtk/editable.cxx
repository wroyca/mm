// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/editable_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  Editable_signal_insert_text_callback (GtkEditable* self,
                                        const char* text,
                                        int length,
                                        int* position,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&, int*)>;

    auto obj = dynamic_cast<Editable*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::ustring (text, text + length),
                                            position);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Editable_signal_insert_text_info = {
      "insert_text",
      (GCallback) &Editable_signal_insert_text_callback,
      (GCallback) &Editable_signal_insert_text_callback};

  static auto
  Editable_signal_delete_text_callback (GtkEditable* self,
                                        gint p0,
                                        gint p1,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (int, int)>;

    auto obj = dynamic_cast<Editable*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Editable_signal_delete_text_info = {
      "delete_text",
      (GCallback) &Editable_signal_delete_text_callback,
      (GCallback) &Editable_signal_delete_text_callback};

  static const Glib::SignalProxyInfo Editable_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkEditable* object, bool take_copy) -> Glib::RefPtr<Gtk::Editable>
  {
    return Glib::make_refptr_for_instance<Gtk::Editable> (
        dynamic_cast<Gtk::Editable*> (
            Glib::wrap_auto_interface<Gtk::Editable> ((GObject*) (object),
                                                      take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Editable_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Editable_Class::iface_init_function;

      gtype_ = gtk_editable_get_type ();
    }

    return *this;
  }

  auto
  Editable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->do_insert_text = &do_insert_text_vfunc_callback;
    klass->do_delete_text = &do_delete_text_vfunc_callback;
    klass->get_text = &get_text_vfunc_callback;
    klass->set_selection_bounds = &set_selection_bounds_vfunc_callback;
    klass->get_selection_bounds = &get_selection_bounds_vfunc_callback;

    klass->insert_text = &insert_text_callback;
    klass->delete_text = &delete_text_callback;
    klass->changed = &changed_callback;
  }

  auto
  Editable_Class::do_insert_text_vfunc_callback (GtkEditable* self,
                                                 const char* text,
                                                 int length,
                                                 int* position) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->insert_text_vfunc (Glib::ustring (text, text + length),
                                  *position);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->do_insert_text)
      (*base->do_insert_text) (self, text, length, position);
  }

  auto
  Editable_Class::do_delete_text_vfunc_callback (GtkEditable* self,
                                                 int start_pos,
                                                 int end_pos) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->delete_text_vfunc (start_pos, end_pos);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->do_delete_text)
      (*base->do_delete_text) (self, start_pos, end_pos);
  }

  auto
  Editable_Class::get_text_vfunc_callback (GtkEditable* self) -> const char*
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          static auto quark_return_value =
              g_quark_from_static_string ("Gtk::Editable::get_text_vfunc");

          auto return_value = static_cast<Glib::ustring*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new Glib::ustring ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &Glib::destroy_notify_delete<Glib::ustring>);
          }

          *return_value = obj->get_text_vfunc ();
          return ((*return_value)).c_str ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_text)
      return (*base->get_text) (self);

    using RType = const char*;
    return RType ();
  }

  auto
  Editable_Class::set_selection_bounds_vfunc_callback (GtkEditable* self,
                                                       int start_pos,
                                                       int end_pos) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->select_region_vfunc (start_pos, end_pos);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->set_selection_bounds)
      (*base->set_selection_bounds) (self, start_pos, end_pos);
  }

  auto
  Editable_Class::get_selection_bounds_vfunc_callback (GtkEditable* self,
                                                       int* start_pos,
                                                       int* end_pos) -> gboolean
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (
              obj->get_selection_bounds_vfunc (*(start_pos), *(end_pos)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_selection_bounds)
      return (*base->get_selection_bounds) (self, start_pos, end_pos);

    using RType = gboolean;
    return RType ();
  }

  auto
  Editable_Class::insert_text_callback (GtkEditable* self,
                                        const char* text,
                                        int length,
                                        int* position) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_insert_text (Glib::ustring (text, text + length), position);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->insert_text)
      (*base->insert_text) (self, text, length, position);
  }

  auto
  Editable_Class::delete_text_callback (GtkEditable* self, gint p0, gint p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_delete_text (p0, p1);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->delete_text)
      (*base->delete_text) (self, p0, p1);
  }

  auto
  Editable_Class::changed_callback (GtkEditable* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  Editable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Editable ((GtkEditable*) (object));
  }

  Editable::Editable ()
    : Glib::Interface (editable_class_.init ())
  {
  }

  Editable::Editable (GtkEditable* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  Editable::Editable (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  Editable::Editable (Editable&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  Editable::operator= (Editable&& src) noexcept -> Editable&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  Editable::~Editable () noexcept {}

  auto
  Editable::add_interface (GType gtype_implementer) -> void
  {
    editable_class_.init ().add_interface (gtype_implementer);
  }

  Editable::CppClassType Editable::editable_class_;

  auto
  Editable::get_type () -> GType
  {
    return editable_class_.init ().get_type ();
  }

  auto
  Editable::get_base_type () -> GType
  {
    return gtk_editable_get_type ();
  }

  auto
  Editable::get_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_editable_get_text (const_cast<GtkEditable*> (gobj ())));
  }

  auto
  Editable::set_text (const Glib::ustring& text) -> void
  {
    gtk_editable_set_text (gobj (), text.c_str ());
  }

  auto
  Editable::delete_selection () -> void
  {
    gtk_editable_delete_selection (gobj ());
  }

  auto
  Editable::set_editable (bool is_editable) -> void
  {
    gtk_editable_set_editable (gobj (), static_cast<int> (is_editable));
  }

  auto
  Editable::get_editable () const -> bool
  {
    return gtk_editable_get_editable (const_cast<GtkEditable*> (gobj ()));
  }

  auto
  Editable::insert_text (const Glib::ustring& new_text,
                         int new_text_length,
                         int& position) -> void
  {
    gtk_editable_insert_text (gobj (),
                              new_text.c_str (),
                              new_text_length,
                              &(position));
  }

  auto
  Editable::delete_text (int start_pos, int end_pos) -> void
  {
    gtk_editable_delete_text (gobj (), start_pos, end_pos);
  }

  auto
  Editable::get_chars (int start_pos, int end_pos) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_editable_get_chars (const_cast<GtkEditable*> (gobj ()),
                                start_pos,
                                end_pos));
  }

  auto
  Editable::select_region (int start_pos, int end_pos) -> void
  {
    gtk_editable_select_region (gobj (), start_pos, end_pos);
  }

  auto
  Editable::get_selection_bounds (int& start_pos, int& end_pos) const -> bool
  {
    return gtk_editable_get_selection_bounds (
        const_cast<GtkEditable*> (gobj ()),
        &(start_pos),
        &(end_pos));
  }

  auto
  Editable::set_position (int position) -> void
  {
    gtk_editable_set_position (gobj (), position);
  }

  auto
  Editable::get_position () const -> int
  {
    return gtk_editable_get_position (const_cast<GtkEditable*> (gobj ()));
  }

  auto
  Editable::get_alignment () const -> float
  {
    return gtk_editable_get_alignment (const_cast<GtkEditable*> (gobj ()));
  }

  auto
  Editable::set_alignment (float xalign) -> void
  {
    gtk_editable_set_alignment (gobj (), xalign);
  }

  auto
  Editable::get_width_chars () const -> int
  {
    return gtk_editable_get_width_chars (const_cast<GtkEditable*> (gobj ()));
  }

  auto
  Editable::set_width_chars (int n_chars) -> void
  {
    gtk_editable_set_width_chars (gobj (), n_chars);
  }

  auto
  Editable::get_max_width_chars () const -> int
  {
    return gtk_editable_get_max_width_chars (
        const_cast<GtkEditable*> (gobj ()));
  }

  auto
  Editable::set_max_width_chars (int n_chars) -> void
  {
    gtk_editable_set_max_width_chars (gobj (), n_chars);
  }

  auto
  Editable::get_enable_undo () const -> bool
  {
    return gtk_editable_get_enable_undo (const_cast<GtkEditable*> (gobj ()));
  }

  auto
  Editable::set_enable_undo (bool enable_undo) -> void
  {
    gtk_editable_set_enable_undo (gobj (), static_cast<int> (enable_undo));
  }

  auto
  Editable::signal_insert_text () -> Glib::SignalProxy<void (const Glib::ustring&, int*)>
  {
    return Glib::SignalProxy<void (const Glib::ustring&, int*)> (
        this,
        &Editable_signal_insert_text_info);
  }

  auto
  Editable::signal_delete_text () -> Glib::SignalProxy<void (int, int)>
  {
    return Glib::SignalProxy<void (int, int)> (
        this,
        &Editable_signal_delete_text_info);
  }

  auto
  Editable::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Editable_signal_changed_info);
  }

  auto
  Editable::property_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text");
  }

  auto
  Editable::property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text");
  }

  auto
  Editable::property_cursor_position () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "cursor-position");
  }

  auto
  Editable::property_enable_undo () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-undo");
  }

  auto
  Editable::property_enable_undo () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-undo");
  }

  auto
  Editable::property_selection_bound () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "selection-bound");
  }

  auto
  Editable::property_editable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "editable");
  }

  auto
  Editable::property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "editable");
  }

  auto
  Editable::property_width_chars () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "width-chars");
  }

  auto
  Editable::property_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "width-chars");
  }

  auto
  Editable::property_max_width_chars () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "max-width-chars");
  }

  auto
  Editable::property_max_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "max-width-chars");
  }

  auto
  Editable::property_xalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  Editable::property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  Gtk::Editable::on_insert_text (const Glib::ustring& text, int* position) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->insert_text)
      (*base->insert_text) (gobj (), text.data (), text.bytes (), position);
  }

  auto
  Gtk::Editable::on_delete_text (int start_pos, int end_pos) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->delete_text)
      (*base->delete_text) (gobj (), start_pos, end_pos);
  }

  auto
  Gtk::Editable::on_changed () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

  auto
  Gtk::Editable::insert_text_vfunc (const Glib::ustring& text, int& position) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->do_insert_text)
    {
      (*base->do_insert_text) (gobj (), text.data (), text.bytes (), &position);
    }
  }

  auto
  Gtk::Editable::delete_text_vfunc (int start_pos, int end_pos) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->do_delete_text)
    {
      (*base->do_delete_text) (gobj (), start_pos, end_pos);
    }
  }

  auto
  Gtk::Editable::get_text_vfunc () const -> Glib::ustring
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_text)
    {
      Glib::ustring retval (Glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_text) (const_cast<GtkEditable*> (gobj ()))));
      return retval;
    }

    using RType = Glib::ustring;
    return RType ();
  }

  auto
  Gtk::Editable::select_region_vfunc (int start_pos, int end_pos) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_selection_bounds)
    {
      (*base->set_selection_bounds) (gobj (), start_pos, end_pos);
    }
  }

  auto
  Gtk::Editable::get_selection_bounds_vfunc (int& start_pos, int& end_pos) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_selection_bounds)
    {
      bool retval (
          (*base->get_selection_bounds) (const_cast<GtkEditable*> (gobj ()),
                                         &(start_pos),
                                         &(end_pos)));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gtk
