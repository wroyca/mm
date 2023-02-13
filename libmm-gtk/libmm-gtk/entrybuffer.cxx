


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/entrybuffer.hxx>
#include <libmm-gtk/entrybuffer_p.hxx>


/* Copyright(C) 1998-2002 The gtkmm Development Team
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
#include <glib.h>


namespace Gtk
{

EntryBuffer::EntryBuffer(const Glib::ustring& text)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(entrybuffer_class_.init()))
{
  set_text(text);
}

auto EntryBuffer::set_text (const Glib::ustring &text) -> void
{
  gtk_entry_buffer_set_text(gobj(), text.c_str(), -1 /* see docs */);
}

auto EntryBuffer::insert_text(
  const guint position, const Glib::ustring& text) -> guint
{
  return gtk_entry_buffer_insert_text(gobj(), position, text.c_str(), -1 /* see docs */);
}

auto EntryBuffer::emit_inserted_text (
  const guint position, const Glib::ustring &text) -> void
{
  gtk_entry_buffer_emit_inserted_text(gobj(), position, text.c_str(), -1 /* see docs */);
}

} // namespace Gtk

namespace
{


auto EntryBuffer_signal_inserted_text_callback (
  GtkEntryBuffer *self, const guint p0, const gchar *p1, const guint p2, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint, const char*, guint)>;

  const auto obj = dynamic_cast<EntryBuffer*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1
, p2);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo EntryBuffer_signal_inserted_text_info =
{
  "inserted-text",
  (GCallback) &EntryBuffer_signal_inserted_text_callback,
  (GCallback) &EntryBuffer_signal_inserted_text_callback
};


auto EntryBuffer_signal_deleted_text_callback (
  GtkEntryBuffer *self, const guint p0, const guint p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint, guint)>;

  const auto obj = dynamic_cast<EntryBuffer*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo EntryBuffer_signal_deleted_text_info =
{
  "deleted-text",
  (GCallback) &EntryBuffer_signal_deleted_text_callback,
  (GCallback) &EntryBuffer_signal_deleted_text_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkEntryBuffer* object, const bool take_copy) -> RefPtr<Gtk::EntryBuffer>
{
  return Glib::make_refptr_for_instance<Gtk::EntryBuffer>( dynamic_cast<Gtk::EntryBuffer*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EntryBuffer_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EntryBuffer_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_entry_buffer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto EntryBuffer_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->inserted_text = &inserted_text_callback;
  klass->deleted_text = &deleted_text_callback;
}


auto EntryBuffer_Class::inserted_text_callback (
  GtkEntryBuffer *self, const guint p0, const gchar *p1, const guint p2) -> void
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
        obj->on_inserted_text(p0, p1
, p2);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->inserted_text)
    (*base->inserted_text)(self, p0, p1, p2);
}
auto EntryBuffer_Class::deleted_text_callback (GtkEntryBuffer *self, const guint p0, const guint p1) -> void
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
        obj->on_deleted_text(p0, p1);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->deleted_text)
    (*base->deleted_text)(self, p0, p1);
}


auto EntryBuffer_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EntryBuffer((GtkEntryBuffer*)object);
}


/* The implementation: */

auto EntryBuffer::gobj_copy() -> GtkEntryBuffer*
{
  reference();
  return gobj();
}

EntryBuffer::EntryBuffer(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

EntryBuffer::EntryBuffer(GtkEntryBuffer* castitem)
: Object((GObject*)castitem)
{}


EntryBuffer::EntryBuffer(EntryBuffer&& src) noexcept
: Object(std::move(src))
{}

auto EntryBuffer::operator=(EntryBuffer&& src) noexcept -> EntryBuffer&
{
  Object::operator=(std::move(src));
  return *this;
}


EntryBuffer::~EntryBuffer() noexcept = default;

EntryBuffer::CppClassType EntryBuffer::entrybuffer_class_; // initialize static member

auto EntryBuffer::get_type() -> GType
{
  return entrybuffer_class_.init().get_type();
}


auto EntryBuffer::get_base_type() -> GType
{
  return gtk_entry_buffer_get_type();
}


EntryBuffer::EntryBuffer()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(entrybuffer_class_.init()))
{


}

auto EntryBuffer::create() -> Glib::RefPtr<EntryBuffer>
{
  return Glib::make_refptr_for_instance<EntryBuffer>( new EntryBuffer() );
}

auto EntryBuffer::create(const Glib::ustring& text) -> Glib::RefPtr<EntryBuffer>
{
  return Glib::make_refptr_for_instance<EntryBuffer>( new EntryBuffer(text) );
}

auto EntryBuffer::get_bytes() const -> gsize
{
  return gtk_entry_buffer_get_bytes(const_cast<GtkEntryBuffer*>(gobj()));
}

auto EntryBuffer::get_length() const -> guint
{
  return gtk_entry_buffer_get_length(const_cast<GtkEntryBuffer*>(gobj()));
}

auto EntryBuffer::get_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_entry_buffer_get_text(const_cast<GtkEntryBuffer*>(gobj())));
}

auto EntryBuffer::set_max_length (
  const int max_length) -> void
{
  gtk_entry_buffer_set_max_length(gobj(), max_length);
}

auto EntryBuffer::get_max_length() const -> int
{
  return gtk_entry_buffer_get_max_length(const_cast<GtkEntryBuffer*>(gobj()));
}

auto EntryBuffer::delete_text(
  const guint position, const int n_chars) -> guint
{
  return gtk_entry_buffer_delete_text(gobj(), position, n_chars);
}

auto EntryBuffer::emit_deleted_text (
  const guint position, const guint n_chars) -> void
{
  gtk_entry_buffer_emit_deleted_text(gobj(), position, n_chars);
}


auto EntryBuffer::signal_inserted_text() -> Glib::SignalProxy<void(guint, const char*, guint)>
{
  return {this, &EntryBuffer_signal_inserted_text_info};
}


auto EntryBuffer::signal_deleted_text() -> Glib::SignalProxy<void(guint, guint)>
{
  return {this, &EntryBuffer_signal_deleted_text_info};
}


auto EntryBuffer::property_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "text"};
}

auto EntryBuffer::property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "text"};
}

auto EntryBuffer::property_length() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "length"};
}

auto EntryBuffer::property_max_length() -> Glib::PropertyProxy< int >
{
  return {this, "max-length"};
}

auto EntryBuffer::property_max_length() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-length"};
}


auto EntryBuffer::on_inserted_text (
  const guint position, const char *chars, const guint n_chars) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->inserted_text)
    (*base->inserted_text)(gobj(),position,chars,n_chars);
}
auto EntryBuffer::on_deleted_text (
  const guint position, const guint n_chars) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->deleted_text)
    (*base->deleted_text)(gobj(),position,n_chars);
}


} // namespace Gtk

