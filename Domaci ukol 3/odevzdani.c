#define ACCURACY 100
int lower ( double x, double y )
{
    if ( y - x > fabs(x) * ACCURACY * DBL_EPSILON)
    {
        return 1;
    }
    return 0;
}

int almostEqual ( double x, double y )
{
    if (fabs(x - y) < fabs(x) * ACCURACY * DBL_EPSILON)
    {
        return 1;
    }
    return 0;
}

typedef struct {
    double x, y;
}POINT;

typedef struct {
    double k, b, x;     //x only for k == infinity
    POINT start, finish;

}LINE;

typedef struct {
    POINT upper_left, lower_right;
}RECTANGLE;

void defineLine(POINT * start, POINT * finish, LINE * line)
{
    line->start = *start;
    line->finish = *finish;
    line->k = (finish->y - start->y) / (finish->x - start->x);
    line->b = finish->y - (line->k * finish->x);
    if (line->k == INFINITY || line->k == -INFINITY)
        line->x = start->x;
}

void defineRectangle(const POINT * first, const POINT * second, RECTANGLE * rect)
{
    if (first->x < second->x && first->y > second->y)
    {
        rect->upper_left = *first;
        rect->lower_right = *second;
    }
    else if (first->x > second->x && first->y < second->y)
    {
        rect->upper_left = *second;
        rect->lower_right = *first;
    }
    else if (first->x > second->x && first->y > second->y)
    {
        rect->upper_left.x = second->x;
        rect->upper_left.y = first->y;
        rect->lower_right.x = first->x;
        rect->lower_right.y = second->y;
    }
    else
    {
        rect->upper_left.x = first->x;
        rect->upper_left.y = second->y;
        rect->lower_right.x = second->x;
        rect->lower_right.y = first->y;
    }
}

void getPointOfTheLine(const int mode, const LINE * line, POINT * end_of_view)
// mode == 0: find x
// mode == 1: find y
{
    if (mode == 0 && (line->k == INFINITY || line->k == -INFINITY))
        end_of_view->x = line->x;

    else if (mode == 1 && line->k == 0)
        end_of_view->y = line->b;

    else if (mode == 0)
    {
        end_of_view->x = (end_of_view->y - line->b) / line->k;
    }

    else if (mode == 1)
    {
        end_of_view->y = line->k * end_of_view->x + line->b;
    }

    else
        assert(1 == 0);
}

void cutLine(POINT * point, const LINE * line, const RECTANGLE * rect)
{
    if (point->x < rect->upper_left.x)
    {
        point->x = rect->upper_left.x;
        getPointOfTheLine(1, line, point);
    }
    if (point->x > rect->lower_right.x)
    {
        point->x = rect->lower_right.x;
        getPointOfTheLine(1, line, point);
    }
    if (point->y > rect->upper_left.y)
    {
        point->y = rect->upper_left.y;
        getPointOfTheLine(0, line, point);
    }
    if (point->y < rect->lower_right.y)
    {
        point->y = rect->lower_right.y;
        getPointOfTheLine(0, line, point);
    }
}

int clipLine ( double rx1, double ry1, double rx2, double ry2, double * ax, double * ay, double * bx, double * by )
{
    if ((lower(*ax, rx1) && lower(*ax, rx2) && lower(*bx, rx1) && lower(*bx, rx2))
        || (lower(rx1, *ax) && lower(rx2, *ax) && lower(rx1, *bx) && lower(rx2, *bx))
        || (lower(*ay, ry1) && lower(*ay, ry2) && lower(*by, ry1) && lower(*by, ry2))
        || (lower(ry1, *ay) && lower(ry2, *ay) && lower(ry1, *by) && lower(ry2, *by)))
        return 0;

    LINE line;
    POINT tmp_start, tmp_finish;
    RECTANGLE rect;

    tmp_start.x = rx1;
    tmp_start.y = ry1;
    tmp_finish.x = rx2;
    tmp_finish.y = ry2;
    defineRectangle(&tmp_start, &tmp_finish, &rect);

    tmp_start.x = *ax;
    tmp_start.y = *ay;
    tmp_finish.x = *bx;
    tmp_finish.y = *by;
    defineLine(&tmp_start, &tmp_finish, &line);

    cutLine(&line.start, &line, &rect);
    cutLine(&line.finish, &line, &rect);

    if (almostEqual(line.start.x, line.finish.x) && almostEqual(line.start.y, line.finish.y)
        && (lower(line.start.x, rect.upper_left.x) || lower(rect.lower_right.x, line.start.x)))
        return 0;

    *ax = line.start.x;
    *ay = line.start.y;
    *bx = line.finish.x;
    *by = line.finish.y;

    return 1;
}
