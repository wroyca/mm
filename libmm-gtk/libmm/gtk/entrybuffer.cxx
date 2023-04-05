// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/entrybuffer.hxx>
#include <libmm/gtk/entrybuffer_p.hxx>

#include <glib.h>
#include <gtk/gtk.h>

namespace gtk
{

  EntryBuffer::EntryBuffer (const glib::ustring& text)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (entrybuffer_class_.init ()))
  {
    set_text (text);
  }

  auto
  EntryBuffer::set_text (const glib::ustring& text) -> void
  {
    gtk_entry_buffer_set_text (gobj (), text.c_str (), -1);
  }

  auto
  EntryBuffer::insert_text (guint position, const glib::ustring& text) -> guint
  {
    return gtk_entry_buffer_insert_text (gobj (), position, text.c_str (), -1);
  }

  auto
  EntryBuffer::emit_inserted_text (guint position, const glib::ustring& text) -> void
  {
    gtk_entry_buffer_emit_inserted_text (gobj (), position, text.c_str (), -1);
  }

} // namespace gtk

namespace
{

  static auto
  EntryBuffer_signal_inserted_text_callback (GtkEntryBuffer* self,
                                             guint p0,
                                             const gchar* p1,
                                             guint p2,
                                             void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint, const char*, guint)>;

    auto obj = dynamic_cast<EntryBuffer*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo EntryBuffer_signal_inserted_text_info = {
      "inserted-text",
      (GCallback) &EntryBuffer_signal_inserted_text_callback,
      (GCallback) &EntryBuffer_signal_inserted_text_callback};

  static auto
  EntryBuffer_signal_deleted_text_callback (GtkEntryBuffer* self,
                                            guint p0,
                                            guint p1,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint, guint)>;

    auto obj = dynamic_cast<EntryBuffer*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo EntryBuffer_signal_deleted_text_info = {
      "deleted-text",
      (GCallback) &EntryBuffer_signal_deleted_text_callback,
      (GCallback) &EntryBuffer_signal_deleted_text_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkEntryBuffer* object, bool take_copy) -> glib::RefPtr<gtk::EntryBuffer>
  {
    return glib::make_refptr_for_instance<gtk::EntryBuffer> (
        dynamic_cast<gtk::EntryBuffer*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EntryBuffer_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EntryBuffer_Class::class_init_function;

      register_derived_type (gtk_entry_buffer_get_type ());
    }

    return *this;
  }

  auto
  EntryBuffer_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->inserted_text = &inserted_text_callback;
    klass->deleted_text = &deleted_text_callback;
  }

  auto
  EntryBuffer_Class::inserted_text_callback (GtkEntryBuffer* self,
                                             guint p0,
                                             const gchar* p1,
                                             guint p2) -> void
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
          obj->on_inserted_text (p0, p1, p2);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->inserted_text)
      (*base->inserted_text) (self, p0, p1, p2);
  }

  auto
  EntryBuffer_Class::deleted_text_callback (GtkEntryBuffer* self,
                                            guint p0,
                                            guint p1) -> void
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
          obj->on_deleted_text (p0, p1);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->deleted_text)
      (*base->deleted_text) (self, p0, p1);
  }

  auto
  EntryBuffer_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EntryBuffer ((GtkEntryBuffer*) object);
  }

  auto
  EntryBuffer::gobj_copy () -> GtkEntryBuffer*
  {
    reference ();
    return gobj ();
  }

  EntryBuffer::EntryBuffer (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  EntryBuffer::EntryBuffer (GtkEntryBuffer* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  EntryBuffer::EntryBuffer (EntryBuffer&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  EntryBuffer::operator= (EntryBuffer&& src) noexcept -> EntryBuffer&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  EntryBuffer::~EntryBuffer () noexcept {}

  EntryBuffer::CppClassType EntryBuffer::entrybuffer_class_;

  auto
  EntryBuffer::get_type () -> GType
  {
    return entrybuffer_class_.init ().get_type ();
  }

  auto
  EntryBuffer::get_base_type () -> GType
  {
    return gtk_entry_buffer_get_type ();
  }

  EntryBuffer::EntryBuffer ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (entrybuffer_class_.init ()))
  {
  }

  auto
  EntryBuffer::create () -> glib::RefPtr<EntryBuffer>
  {
    return glib::make_refptr_for_instance<EntryBuffer> (new EntryBuffer ());
  }

  auto
  EntryBuffer::create (const glib::ustring& text) -> glib::RefPtr<EntryBuffer>
  {
    return glib::make_refptr_for_instance<EntryBuffer> (new EntryBuffer (text));
  }

  auto
  EntryBuffer::get_bytes () const -> gsize
  {
    return gtk_entry_buffer_get_bytes (const_cast<GtkEntryBuffer*> (gobj ()));
  }

  auto
  EntryBuffer::get_length () const -> guint
  {
    return gtk_entry_buffer_get_length (const_cast<GtkEntryBuffer*> (gobj ()));
  }

  auto
  EntryBuffer::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_entry_buffer_get_text (const_cast<GtkEntryBuffer*> (gobj ())));
  }

  auto
  EntryBuffer::set_max_length (int max_length) -> void
  {
    gtk_entry_buffer_set_max_length (gobj (), max_length);
  }

  auto
  EntryBuffer::get_max_length () const -> int
  {
    return gtk_entry_buffer_get_max_length (
        const_cast<GtkEntryBuffer*> (gobj ()));
  }

  auto
  EntryBuffer::delete_text (guint position, int n_chars) -> guint
  {
    return gtk_entry_buffer_delete_text (gobj (), position, n_chars);
  }

  auto
  EntryBuffer::emit_deleted_text (guint position, guint n_chars) -> void
  {
    gtk_entry_buffer_emit_deleted_text (gobj (), position, n_chars);
  }

  auto
  EntryBuffer::signal_inserted_text () -> glib::SignalProxy<void (guint, const char*, guint)>
  {
    return glib::SignalProxy<void (guint, const char*, guint)> (
        this,
        &EntryBuffer_signal_inserted_text_info);
  }

  auto
  EntryBuffer::signal_deleted_text () -> glib::SignalProxy<void (guint, guint)>
  {
    return glib::SignalProxy<void (guint, guint)> (
        this,
        &EntryBuffer_signal_deleted_text_info);
  }

  auto
  EntryBuffer::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text");
  }

  auto
  EntryBuffer::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text");
  }

  auto
  EntryBuffer::property_length () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "length");
  }

  auto
  EntryBuffer::property_max_length () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-length");
  }

  auto
  EntryBuffer::property_max_length () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-length");
  }

  auto
  gtk::EntryBuffer::on_inserted_text (guint position,
                                      const char* chars,
                                      guint n_chars) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->inserted_text)
      (*base->inserted_text) (gobj (), position, chars, n_chars);
  }

  auto
  gtk::EntryBuffer::on_deleted_text (guint position, guint n_chars) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->deleted_text)
      (*base->deleted_text) (gobj (), position, n_chars);
  }

} // namespace gtk
