
#ifndef _GIOMM_FILENAMECOMPLETER_H
#define _GIOMM_FILENAMECOMPLETER_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFilenameCompleter = struct _GFilenameCompleter;
using GFilenameCompleterClass = struct _GFilenameCompleterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API FilenameCompleter_Class;
}
#endif

namespace Gio
{

  class GIOMM_API File;

  class GIOMM_API FilenameCompleter : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FilenameCompleter;
    using CppClassType = FilenameCompleter_Class;
    using BaseObjectType = GFilenameCompleter;
    using BaseClassType = GFilenameCompleterClass;

    FilenameCompleter (const FilenameCompleter&) = delete;
    auto
    operator= (const FilenameCompleter&) -> FilenameCompleter& = delete;

  private:
    friend class FilenameCompleter_Class;
    static CppClassType filenamecompleter_class_;

  protected:
    explicit FilenameCompleter (const Glib::ConstructParams& construct_params);
    explicit FilenameCompleter (GFilenameCompleter* castitem);

#endif

  public:
    FilenameCompleter (FilenameCompleter&& src) noexcept;
    auto
    operator= (FilenameCompleter&& src) noexcept -> FilenameCompleter&;

    ~FilenameCompleter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFilenameCompleter*
    {
      return reinterpret_cast<GFilenameCompleter*> (gobject_);
    }

    auto
    gobj () const -> const GFilenameCompleter*
    {
      return reinterpret_cast<GFilenameCompleter*> (gobject_);
    }

    auto
    gobj_copy () -> GFilenameCompleter*;

  private:
  protected:
    FilenameCompleter ();

  public:
    static auto
    create () -> Glib::RefPtr<FilenameCompleter>;

    auto
    get_completion_suffix (const std::string& initial_text) const
        -> std::string;

    auto
    get_completions (const std::string& initial_text) const
        -> std::vector<Glib::ustring>;

    void
    set_dirs_only (bool dirs_only = true);

    auto
    signal_got_completion_data () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual void
    on_got_completion_data ();
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFilenameCompleter* object, bool take_copy = false) -> Glib::RefPtr<Gio::FilenameCompleter>;
} // namespace Glib

#endif
