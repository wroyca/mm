// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/pagesetup.hxx>
#include <libmm/gtk/pagesetup_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  PageSetup::create_from_key_file (
      const Glib::RefPtr<const Glib::KeyFile>& key_file) -> Glib::RefPtr<PageSetup>
  {
    auto result = PageSetup::create ();

    result->load_from_key_file (key_file);

    return result;
  }

  auto
  PageSetup::create_from_key_file (
      const Glib::RefPtr<const Glib::KeyFile>& key_file,
      const Glib::ustring& group_name) -> Glib::RefPtr<PageSetup>
  {
    auto result = PageSetup::create ();

    result->load_from_key_file (key_file, group_name);

    return result;
  }

  auto
  PageSetup::create_from_file (const std::string& file_name) -> Glib::RefPtr<PageSetup>
  {
    auto result = PageSetup::create ();

    result->load_from_file (file_name);

    return result;
  }

  auto
  PageSetup::save_to_key_file (
      const Glib::RefPtr<Glib::KeyFile>& key_file) const -> void
  {
    gtk_page_setup_to_key_file (const_cast<GtkPageSetup*> (gobj ()),
                                Glib::unwrap (key_file),
                                nullptr);
  }

  auto
  PageSetup::load_from_key_file (
      const Glib::RefPtr<const Glib::KeyFile>& key_file) -> bool
  {
    GError* gerror = nullptr;
    bool retvalue = gtk_page_setup_load_key_file (
        gobj (),
        const_cast<GKeyFile*> (Glib::unwrap (key_file)),
        nullptr,
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);

    return retvalue;
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkPageSetup* object, bool take_copy) -> Glib::RefPtr<Gtk::PageSetup>
  {
    return Glib::make_refptr_for_instance<Gtk::PageSetup> (
        dynamic_cast<Gtk::PageSetup*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PageSetup_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PageSetup_Class::class_init_function;

      register_derived_type (gtk_page_setup_get_type ());
    }

    return *this;
  }

  auto
  PageSetup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PageSetup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PageSetup ((GtkPageSetup*) object);
  }

  auto
  PageSetup::gobj_copy () -> GtkPageSetup*
  {
    reference ();
    return gobj ();
  }

  PageSetup::PageSetup (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  PageSetup::PageSetup (GtkPageSetup* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  PageSetup::PageSetup (PageSetup&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  PageSetup::operator= (PageSetup&& src) noexcept -> PageSetup&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  PageSetup::~PageSetup () noexcept {}

  PageSetup::CppClassType PageSetup::pagesetup_class_;

  auto
  PageSetup::get_type () -> GType
  {
    return pagesetup_class_.init ().get_type ();
  }

  auto
  PageSetup::get_base_type () -> GType
  {
    return gtk_page_setup_get_type ();
  }

  PageSetup::PageSetup ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (pagesetup_class_.init ()))
  {
  }

  auto
  PageSetup::create () -> Glib::RefPtr<PageSetup>
  {
    return Glib::make_refptr_for_instance<PageSetup> (new PageSetup ());
  }

  auto
  PageSetup::copy () const -> Glib::RefPtr<PageSetup>
  {
    return Glib::wrap (
        gtk_page_setup_copy (const_cast<GtkPageSetup*> (gobj ())));
  }

  auto
  PageSetup::load_from_file (const std::string& file_name) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue =
        gtk_page_setup_load_file (gobj (), file_name.c_str (), &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PageSetup::load_from_key_file (
      const Glib::RefPtr<const Glib::KeyFile>& key_file,
      const Glib::ustring& group_name) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_page_setup_load_key_file (
        gobj (),
        const_cast<GKeyFile*> (Glib::unwrap (key_file)),
        group_name.c_str (),
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PageSetup::get_orientation () const -> PageOrientation
  {
    return static_cast<PageOrientation> (
        gtk_page_setup_get_orientation (const_cast<GtkPageSetup*> (gobj ())));
  }

  auto
  PageSetup::set_orientation (PageOrientation orientation) -> void
  {
    gtk_page_setup_set_orientation (
        gobj (),
        static_cast<GtkPageOrientation> (orientation));
  }

  auto
  PageSetup::get_paper_size () -> PaperSize
  {
    return Glib::wrap (gtk_page_setup_get_paper_size (gobj ()), true);
  }

  auto
  PageSetup::get_paper_size () const -> const PaperSize
  {
    return const_cast<PageSetup*> (this)->get_paper_size ();
  }

  auto
  PageSetup::set_paper_size (const PaperSize& size) -> void
  {
    gtk_page_setup_set_paper_size (gobj (),
                                   const_cast<GtkPaperSize*> ((size).gobj ()));
  }

  auto
  PageSetup::get_top_margin (Unit unit) const -> double
  {
    return gtk_page_setup_get_top_margin (const_cast<GtkPageSetup*> (gobj ()),
                                          static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::set_top_margin (double margin, Unit unit) -> void
  {
    gtk_page_setup_set_top_margin (gobj (),
                                   margin,
                                   static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::get_bottom_margin (Unit unit) const -> double
  {
    return gtk_page_setup_get_bottom_margin (
        const_cast<GtkPageSetup*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::set_bottom_margin (double margin, Unit unit) -> void
  {
    gtk_page_setup_set_bottom_margin (gobj (),
                                      margin,
                                      static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::get_left_margin (Unit unit) const -> double
  {
    return gtk_page_setup_get_left_margin (const_cast<GtkPageSetup*> (gobj ()),
                                           static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::set_left_margin (double margin, Unit unit) -> void
  {
    gtk_page_setup_set_left_margin (gobj (),
                                    margin,
                                    static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::get_right_margin (Unit unit) const -> double
  {
    return gtk_page_setup_get_right_margin (const_cast<GtkPageSetup*> (gobj ()),
                                            static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::set_right_margin (double margin, Unit unit) -> void
  {
    gtk_page_setup_set_right_margin (gobj (),
                                     margin,
                                     static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::set_paper_size_and_default_margins (const PaperSize& size) -> void
  {
    gtk_page_setup_set_paper_size_and_default_margins (
        gobj (),
        const_cast<GtkPaperSize*> ((size).gobj ()));
  }

  auto
  PageSetup::get_paper_width (Unit unit) const -> double
  {
    return gtk_page_setup_get_paper_width (const_cast<GtkPageSetup*> (gobj ()),
                                           static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::get_paper_height (Unit unit) const -> double
  {
    return gtk_page_setup_get_paper_height (const_cast<GtkPageSetup*> (gobj ()),
                                            static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::get_page_width (Unit unit) const -> double
  {
    return gtk_page_setup_get_page_width (const_cast<GtkPageSetup*> (gobj ()),
                                          static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::get_page_height (Unit unit) const -> double
  {
    return gtk_page_setup_get_page_height (const_cast<GtkPageSetup*> (gobj ()),
                                           static_cast<GtkUnit> (unit));
  }

  auto
  PageSetup::save_to_file (const std::string& file_name) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_page_setup_to_file (const_cast<GtkPageSetup*> (gobj ()),
                                            file_name.c_str (),
                                            &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PageSetup::save_to_key_file (const Glib::RefPtr<Glib::KeyFile>& key_file,
                               const Glib::ustring& group_name) const -> void
  {
    gtk_page_setup_to_key_file (const_cast<GtkPageSetup*> (gobj ()),
                                Glib::unwrap (key_file),
                                group_name.c_str ());
  }

} // namespace Gtk
