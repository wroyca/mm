

#ifndef __CAIROMM_PATTERN_H
#define __CAIROMM_PATTERN_H

#include <cairo.h>
#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/surface.hxx>

namespace Cairo
{
  struct ColorStop
  {
    double offset;
    double red, green, blue, alpha;
  };

  class CAIROMM_API Matrix;

  class CAIROMM_API Pattern
  {
  protected:
  public:
    enum class Type
    {
      SOLID = CAIRO_PATTERN_TYPE_SOLID,

      SURFACE = CAIRO_PATTERN_TYPE_SURFACE,

      LINEAR = CAIRO_PATTERN_TYPE_LINEAR,

      RADIAL = CAIRO_PATTERN_TYPE_RADIAL
    };

    enum class Extend
    {
      NONE = CAIRO_EXTEND_NONE,

      REPEAT = CAIRO_EXTEND_REPEAT,

      REFLECT = CAIRO_EXTEND_REFLECT,

      PAD = CAIRO_EXTEND_PAD
    };

    explicit Pattern (cairo_pattern_t* cobject, bool has_reference = false);

    Pattern (const Pattern&) = delete;
    auto
    operator= (const Pattern&) -> Pattern& = delete;

    virtual ~Pattern ();

    void
    set_matrix (const Matrix& matrix);

    void
    get_matrix (Matrix& matrix) const;

    auto
    get_matrix () const -> Matrix;

    auto
    get_type () const -> Type;

    void
    set_extend (Extend extend);

    auto
    get_extend () const -> Extend;

    typedef cairo_pattern_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

    inline auto
    get_status () const -> ErrorStatus
    {
      return cairo_pattern_status (const_cast<cairo_pattern_t*> (cobj ()));
    }
#endif

    void
    reference () const;
    void
    unreference () const;

  protected:
    Pattern ();

    cobject* m_cobject;
  };

  class CAIROMM_API SolidPattern : public Pattern
  {
  protected:
  public:
    explicit SolidPattern (cairo_pattern_t* cobject,
                           bool has_reference = false);

    void
    get_rgba (double& red, double& green, double& blue, double& alpha) const;

    static auto
    create_rgb (double red, double green, double blue) -> RefPtr<SolidPattern>;

    static auto
    create_rgba (double red, double green, double blue, double alpha)
        -> RefPtr<SolidPattern>;

    ~SolidPattern () override;
  };

  class CAIROMM_API SurfacePattern : public Pattern
  {
  protected:
    explicit SurfacePattern (const RefPtr<Surface>& surface);

  public:
    enum class Filter
    {
      FAST = CAIRO_FILTER_FAST,

      GOOD = CAIRO_FILTER_GOOD,

      BEST = CAIRO_FILTER_BEST,

      NEAREST = CAIRO_FILTER_NEAREST,

      BILINEAR = CAIRO_FILTER_BILINEAR,

      GAUSSIAN = CAIRO_FILTER_GAUSSIAN
    };

    explicit SurfacePattern (cairo_pattern_t* cobject,
                             bool has_reference = false);

    auto
    get_surface () const -> RefPtr<const Surface>;
    auto
    get_surface () -> RefPtr<Surface>;

    ~SurfacePattern () override;

    static auto
    create (const RefPtr<Surface>& surface) -> RefPtr<SurfacePattern>;

    void
    set_filter (Filter filter);

    auto
    get_filter () const -> Filter;
  };

  class CAIROMM_API Gradient : public Pattern
  {
  protected:
  public:
    explicit Gradient (cairo_pattern_t* cobject, bool has_reference = false);

    ~Gradient () override;

    void
    add_color_stop_rgb (double offset, double red, double green, double blue);

    void
    add_color_stop_rgba (double offset,
                         double red,
                         double green,
                         double blue,
                         double alpha);

    auto
    get_color_stops () const -> std::vector<ColorStop>;

  protected:
    Gradient ();
  };

  class CAIROMM_API LinearGradient : public Gradient
  {
  protected:
    LinearGradient (double x0, double y0, double x1, double y1);

  public:
    explicit LinearGradient (cairo_pattern_t* cobject,
                             bool has_reference = false);

    void
    get_linear_points (double& x0, double& y0, double& x1, double& y1) const;

    ~LinearGradient () override;

    static auto
    create (double x0, double y0, double x1, double y1)
        -> RefPtr<LinearGradient>;
  };

  class CAIROMM_API RadialGradient : public Gradient
  {
  protected:
    RadialGradient (double cx0,
                    double cy0,
                    double radius0,
                    double cx1,
                    double cy1,
                    double radius1);

  public:
    explicit RadialGradient (cairo_pattern_t* cobject,
                             bool has_reference = false);

    void
    get_radial_circles (double& x0,
                        double& y0,
                        double& r0,
                        double& x1,
                        double& y1,
                        double& r1) const;

    ~RadialGradient () override;

    static auto
    create (double cx0,
            double cy0,
            double radius0,
            double cx1,
            double cy1,
            double radius1) -> RefPtr<RadialGradient>;
  };

} // namespace Cairo

#endif
