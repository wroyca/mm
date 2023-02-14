
#ifndef _GTKMM_ASSISTANT_H
#define _GTKMM_ASSISTANT_H

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
  class GTKMM_API Assistant_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Assistant : public Window
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
    friend GTKMM_API class Assistant_Class;
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

    void
    next_page ();

    void
    previous_page ();

    auto
    get_current_page () const -> int;

    void
    set_current_page (int page_num);

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

    void
    remove_page (int page_num);

    typedef sigc::slot<int (int)> SlotForwardPage;

    void
    set_forward_page_func (const SlotForwardPage& slot);

    void
    set_page_type (const Widget& page, AssistantPage::Type type);

    auto
    get_page_type (const Widget& page) const -> AssistantPage::Type;

    void
    set_page_title (const Widget& page, const Glib::ustring& title);

    auto
    get_page_title (const Widget& page) const -> Glib::ustring;

    void
    set_page_complete (const Widget& page, bool complete = true);

    auto
    get_page_complete (const Widget& page) const -> bool;

    void
    add_action_widget (Widget& child);

    void
    remove_action_widget (Widget& child);

    void
    update_buttons_state ();

    void
    commit ();

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

  GTKMM_API
  auto
  wrap (GtkAssistant* object, bool take_copy = false) -> Gtk::Assistant*;
} // namespace Glib

#endif
