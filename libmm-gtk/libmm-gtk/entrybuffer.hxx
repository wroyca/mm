// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENTRYBUFFER_H
#define _GTKMM_ENTRYBUFFER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-gtk/mm-gtkconfig.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntryBuffer = struct _GtkEntryBuffer;
using GtkEntryBufferClass = struct _GtkEntryBufferClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API EntryBuffer_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API EntryBuffer : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EntryBuffer;
    using CppClassType = EntryBuffer_Class;
    using BaseObjectType = GtkEntryBuffer;
    using BaseClassType = GtkEntryBufferClass;

    EntryBuffer (const EntryBuffer&) = delete;
    auto
    operator= (const EntryBuffer&) -> EntryBuffer& = delete;

  private:
    friend class EntryBuffer_Class;
    static CppClassType entrybuffer_class_;

  protected:
    explicit EntryBuffer (const Glib::ConstructParams& construct_params);
    explicit EntryBuffer (GtkEntryBuffer* castitem);

#endif

  public:
    EntryBuffer (EntryBuffer&& src) noexcept;
    auto
    operator= (EntryBuffer&& src) noexcept -> EntryBuffer&;

    ~EntryBuffer () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEntryBuffer*
    {
      return reinterpret_cast<GtkEntryBuffer*> (gobject_);
    }

    auto
    gobj () const -> const GtkEntryBuffer*
    {
      return reinterpret_cast<GtkEntryBuffer*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEntryBuffer*;

  private:
  protected:
    EntryBuffer ();

    explicit EntryBuffer (const Glib::ustring& text);

  public:
    static auto
    create () -> Glib::RefPtr<EntryBuffer>;

    static auto
    create (const Glib::ustring& text) -> Glib::RefPtr<EntryBuffer>;

    auto
    get_bytes () const -> gsize;

    auto
    get_length () const -> guint;

    auto
    get_text () const -> Glib::ustring;

    void
    set_text (const Glib::ustring& text);

    void
    set_max_length (int max_length);

    auto
    get_max_length () const -> int;

    auto
    insert_text (guint position, const Glib::ustring& text) -> guint;

    auto
    delete_text (guint position, int n_chars) -> guint;

    void
    emit_inserted_text (guint position, const Glib::ustring& text);

    void
    emit_deleted_text (guint position, guint n_chars);

    auto
    signal_inserted_text ()
        -> Glib::SignalProxy<void (guint, const char*, guint)>;

    auto
    signal_deleted_text () -> Glib::SignalProxy<void (guint, guint)>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_length () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_max_length () -> Glib::PropertyProxy<int>;

    auto
    property_max_length () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual void
    on_inserted_text (guint position, const char* chars, guint n_chars);

    virtual void
    on_deleted_text (guint position, guint n_chars);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEntryBuffer* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EntryBuffer>;
} // namespace Glib

#endif
