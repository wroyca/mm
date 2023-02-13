


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/editable_p.hxx>


/* Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>


namespace
{


auto Editable_signal_insert_text_callback (
  GtkEditable *self, const char *text, const int length, int *position, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&, int*)>;

  const auto obj = dynamic_cast<Editable*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(      Glib::ustring(text, text + length), position);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Editable_signal_insert_text_info =
{
  "insert_text",
  (GCallback) &Editable_signal_insert_text_callback,
  (GCallback) &Editable_signal_insert_text_callback
};


auto Editable_signal_delete_text_callback (GtkEditable *self, const gint p0, const gint p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(int, int)>;

  const auto obj = dynamic_cast<Editable*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Editable_signal_delete_text_info =
{
  "delete_text",
  (GCallback) &Editable_signal_delete_text_callback,
  (GCallback) &Editable_signal_delete_text_callback
};


const Glib::SignalProxyInfo Editable_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkEditable* object, const bool take_copy) -> RefPtr<Gtk::Editable>
{
  return Glib::make_refptr_for_instance<Gtk::Editable>( Glib::wrap_auto_interface<Gtk::Editable> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Editable_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Editable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_editable_get_type();
  }

  return *this;
}

auto Editable_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->do_insert_text = &do_insert_text_vfunc_callback;
  klass->do_delete_text = &do_delete_text_vfunc_callback;
  klass->get_text = &get_text_vfunc_callback;
  klass->set_selection_bounds = &set_selection_bounds_vfunc_callback;
  klass->get_selection_bounds = &get_selection_bounds_vfunc_callback;

  klass->insert_text = &insert_text_callback;
  klass->delete_text = &delete_text_callback;
  klass->changed = &changed_callback;
}

auto Editable_Class::do_insert_text_vfunc_callback (
  GtkEditable *self, const char *text, const int length, int *position) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)      self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->insert_text_vfunc(      Glib::ustring(text, text + length), *position);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->do_insert_text)
    (*base->do_insert_text)(      self, text, length, position);
}
auto Editable_Class::do_delete_text_vfunc_callback (
  GtkEditable *self, const int start_pos, const int end_pos) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->delete_text_vfunc(start_pos, end_pos);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->do_delete_text)
    (*base->do_delete_text)(self, start_pos, end_pos);
}
auto Editable_Class::get_text_vfunc_callback(GtkEditable* self) -> const char*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        static auto quark_return_value = g_quark_from_static_string("Gtk::Editable::get_text_vfunc");

        auto return_value = static_cast<Glib::ustring*>(g_object_get_qdata(obj_base->gobj(), quark_return_value));
        if (!return_value)
        {
          return_value = new Glib::ustring();
          g_object_set_qdata_full(obj_base->gobj(), quark_return_value, return_value,
          &Glib::destroy_notify_delete<Glib::ustring>);
        }
        // Keep a copy of the return value. The caller is not expected
        // to free the object that the returned pointer points to.
        *return_value = obj->get_text_vfunc();
        return (*return_value).c_str();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_text)
    return (*base->get_text)(self);

  using RType = const char*;
  return RType();
}
auto Editable_Class::set_selection_bounds_vfunc_callback (
  GtkEditable *self, const int start_pos, const int end_pos) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->select_region_vfunc(start_pos, end_pos);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_selection_bounds)
    (*base->set_selection_bounds)(self, start_pos, end_pos);
}
auto Editable_Class::get_selection_bounds_vfunc_callback(GtkEditable* self, int* start_pos, int* end_pos) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_selection_bounds_vfunc(*start_pos
                                               , *end_pos
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_selection_bounds)
    return (*base->get_selection_bounds)(self, start_pos, end_pos);

  using RType = gboolean;
  return RType();
}

auto Editable_Class::insert_text_callback (
  GtkEditable *self, const char *text, const int length, int *position) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)      self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_insert_text(      Glib::ustring(text, text + length), position);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->insert_text)
    (*base->insert_text)(      self, text, length, position);
}
auto Editable_Class::delete_text_callback (GtkEditable *self, const gint p0, const gint p1) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_delete_text(p0
, p1
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->delete_text)
    (*base->delete_text)(self, p0, p1);
}
auto Editable_Class::changed_callback (GtkEditable *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self);
}


auto Editable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Editable((GtkEditable*)object);
}


/* The implementation: */

Editable::Editable()
: Interface(editable_class_.init())
{}

Editable::Editable(GtkEditable* castitem)
: Interface((GObject*)castitem)
{}

Editable::Editable(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Editable::Editable(Editable&& src) noexcept
: Interface(std::move(src))
{}

auto Editable::operator=(Editable&& src) noexcept -> Editable&
{
  Interface::operator=(std::move(src));
  return *this;
}

Editable::~Editable() noexcept = default;

// static
auto Editable::add_interface (
  const GType gtype_implementer) -> void
{
  editable_class_.init().add_interface(gtype_implementer);
}

Editable::CppClassType Editable::editable_class_; // initialize static member

auto Editable::get_type() -> GType
{
  return editable_class_.init().get_type();
}


auto Editable::get_base_type() -> GType
{
  return gtk_editable_get_type();
}


auto Editable::get_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_editable_get_text(const_cast<GtkEditable*>(gobj())));
}

auto Editable::set_text (const Glib::ustring &text) -> void
{
  gtk_editable_set_text(gobj(), text.c_str());
}

auto Editable::delete_selection () -> void
{
  gtk_editable_delete_selection(gobj());
}

auto Editable::set_editable (
  const bool is_editable) -> void
{
  gtk_editable_set_editable(gobj(), is_editable);
}

auto Editable::get_editable() const -> bool
{
  return gtk_editable_get_editable(const_cast<GtkEditable*>(gobj()));
}

auto Editable::insert_text (
  const Glib::ustring &new_text, const int new_text_length, int &position) -> void
{
  gtk_editable_insert_text(gobj(), new_text.c_str(), new_text_length, &position);
}

auto Editable::delete_text (
  const int start_pos, const int end_pos) -> void
{
  gtk_editable_delete_text(gobj(), start_pos, end_pos);
}

auto Editable::get_chars(
  const int start_pos, const int end_pos) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_editable_get_chars(const_cast<GtkEditable*>(gobj()), start_pos, end_pos));
}

auto Editable::select_region (
  const int start_pos, const int end_pos) -> void
{
  gtk_editable_select_region(gobj(), start_pos, end_pos);
}

auto Editable::get_selection_bounds(int& start_pos, int& end_pos) const -> bool
{
  return gtk_editable_get_selection_bounds(const_cast<GtkEditable*>(gobj()), &start_pos, &end_pos);
}

auto Editable::set_position (
  const int position) -> void
{
  gtk_editable_set_position(gobj(), position);
}

auto Editable::get_position() const -> int
{
  return gtk_editable_get_position(const_cast<GtkEditable*>(gobj()));
}

auto Editable::get_alignment() const -> float
{
  return gtk_editable_get_alignment(const_cast<GtkEditable*>(gobj()));
}

auto Editable::set_alignment (
  const float xalign) -> void
{
  gtk_editable_set_alignment(gobj(), xalign);
}

auto Editable::get_width_chars() const -> int
{
  return gtk_editable_get_width_chars(const_cast<GtkEditable*>(gobj()));
}

auto Editable::set_width_chars (
  const int n_chars) -> void
{
  gtk_editable_set_width_chars(gobj(), n_chars);
}

auto Editable::get_max_width_chars() const -> int
{
  return gtk_editable_get_max_width_chars(const_cast<GtkEditable*>(gobj()));
}

auto Editable::set_max_width_chars (
  const int n_chars) -> void
{
  gtk_editable_set_max_width_chars(gobj(), n_chars);
}

auto Editable::get_enable_undo() const -> bool
{
  return gtk_editable_get_enable_undo(const_cast<GtkEditable*>(gobj()));
}

auto Editable::set_enable_undo (
  const bool enable_undo) -> void
{
  gtk_editable_set_enable_undo(gobj(), enable_undo);
}


auto Editable::signal_insert_text() -> Glib::SignalProxy<void(const Glib::ustring&, int*)>
{
  return {this, &Editable_signal_insert_text_info};
}


auto Editable::signal_delete_text() -> Glib::SignalProxy<void(int, int)>
{
  return {this, &Editable_signal_delete_text_info};
}


auto Editable::signal_changed() -> Glib::SignalProxy<void()>
{
  return {this, &Editable_signal_changed_info};
}


auto Editable::property_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "text"};
}

auto Editable::property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "text"};
}

auto Editable::property_cursor_position() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "cursor-position"};
}

auto Editable::property_enable_undo() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-undo"};
}

auto Editable::property_enable_undo() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-undo"};
}

auto Editable::property_selection_bound() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "selection-bound"};
}

auto Editable::property_editable() -> Glib::PropertyProxy< bool >
{
  return {this, "editable"};
}

auto Editable::property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "editable"};
}

auto Editable::property_width_chars() -> Glib::PropertyProxy< int >
{
  return {this, "width-chars"};
}

auto Editable::property_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "width-chars"};
}

auto Editable::property_max_width_chars() -> Glib::PropertyProxy< int >
{
  return {this, "max-width-chars"};
}

auto Editable::property_max_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-width-chars"};
}

auto Editable::property_xalign() -> Glib::PropertyProxy< float >
{
  return {this, "xalign"};
}

auto Editable::property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return {this, "xalign"};
}


auto Editable::on_insert_text (const Glib::ustring &text, int *position) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->insert_text)
    (*base->insert_text)(gobj(),text.data(),text.bytes(),position);
}
auto Editable::on_delete_text (
  const int start_pos, const int end_pos) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->delete_text)
    (*base->delete_text)(gobj(),start_pos,end_pos);
}
auto Editable::on_changed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->changed)
    (*base->changed)(gobj());
}

auto Editable::insert_text_vfunc (const Glib::ustring &text, int &position) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->do_insert_text)
  {
    (*base->do_insert_text)(gobj(),text.data(),text.bytes(),&position);
  }
}
auto Editable::delete_text_vfunc (
  const int start_pos, const int end_pos) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->do_delete_text)
  {
    (*base->do_delete_text)(gobj(),start_pos,end_pos);
  }
}
auto Editable::get_text_vfunc() const -> Glib::ustring
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_text)
  {
    Glib::ustring retval(Glib::convert_const_gchar_ptr_to_ustring((*base->get_text)(const_cast<GtkEditable*>(gobj()))));
    return retval;
  }

  using RType = Glib::ustring;
  return {};
}
auto Editable::select_region_vfunc (
  const int start_pos, const int end_pos) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->set_selection_bounds)
  {
    (*base->set_selection_bounds)(gobj(),start_pos,end_pos);
  }
}
auto Editable::get_selection_bounds_vfunc(int& start_pos, int& end_pos) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_selection_bounds)
  {
    const bool retval((*base->get_selection_bounds)(const_cast<GtkEditable*>(gobj()),&start_pos,&end_pos));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gtk


