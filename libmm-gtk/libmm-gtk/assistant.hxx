// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ASSISTANT_H
#define _GTKMM_ASSISTANT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gdk/pixbuf.hxx>
  #include <libmm-gio/listmodel.hxx>
  #include <libmm-gtk/assistantpage.hxx>
  #include <libmm-gtk/window.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAssistant = struct _GtkAssistant;
using GtkAssistantClass = struct _GtkAssistantClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Assistant_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Assistant : public Window
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Assistant CppObjectType;
    typedef Assistant_Class CppClassType;
    typedef GtkAssistant BaseObjectType;
    typedef GtkAssistantClass BaseClassType;
  #endif

    Assistant (Assistant&& src) noexcept;
    auto
    operator= (Assistant&& src) noexcept -> Assistant&;

    Assistant (const Assistant&) = delete;
    auto
    operator= (const Assistant&) -> Assistant& = delete;

    ~Assistant () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Assistant_Class;
    static CppClassType assistant_class_;

  protected:
    explicit Assistant (const Glib::ConstructParams& construct_params);
    explicit Assistant (GtkAssistant* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkAssistant*
    {
      return reinterpret_cast<GtkAssistant*> (gobject_);
    }

    auto
    gobj () const -> const GtkAssistant*
    {
      return reinterpret_cast<GtkAssistant*> (gobject_);
    }

  private:
  public:
    Assistant ();

    explicit Assistant (bool use_header_bar);

    auto
    next_page () -> void;

    auto
    previous_page () -> void;

    auto
    get_current_page () const -> int;

    auto
    set_current_page (int page_num) -> void;

    auto
    get_n_pages () const -> int;

    auto
    get_nth_page (int page_num) -> Widget*;

    auto
    get_nth_page (int page_num) const -> const Widget*;

    auto
    prepend_page (Widget& page) -> int;

    auto
    append_page (Widget& page) -> int;

    auto
    insert_page (Widget& page, int position) -> int;

    auto
    remove_page (int page_num) -> void;

    typedef sigc::slot<int (int)> SlotForwardPage;

    auto
    set_forward_page_func (const SlotForwardPage& slot) -> void;

    auto
    set_page_type (const Widget& page, AssistantPage::Type type) -> void;

    auto
    get_page_type (const Widget& page) const -> AssistantPage::Type;

    auto
    set_page_title (const Widget& page, const Glib::ustring& title) -> void;

    auto
    get_page_title (const Widget& page) const -> Glib::ustring;

    auto
    set_page_complete (const Widget& page, bool complete = true) -> void;

    auto
    get_page_complete (const Widget& page) const -> bool;

    auto
    add_action_widget (Widget& child) -> void;

    auto
    remove_action_widget (Widget& child) -> void;

    auto
    update_buttons_state () -> void;

    auto
    commit () -> void;

    auto
    get_page (Widget& child) -> Glib::RefPtr<AssistantPage>;

    auto
    get_page (const Widget& child) const -> Glib::RefPtr<const AssistantPage>;

    auto
    get_pages () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_pages () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    signal_prepare () -> Glib::SignalProxy<void (Gtk::Widget*)>;

    auto
    signal_apply () -> Glib::SignalProxy<void ()>;

    auto
    signal_close () -> Glib::SignalProxy<void ()>;

    auto
    signal_cancel () -> Glib::SignalProxy<void ()>;

    auto
    property_use_header_bar () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAssistant* object, bool take_copy = false) -> Gtk::Assistant*;
} // namespace Glib

#endif

#endif
