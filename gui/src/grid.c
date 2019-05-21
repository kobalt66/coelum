#include "include/grid.h"
#include <coelum/draw_utils.h>
#include <coelum/scene_manager.h>
#include <coelum/utils.h>


extern scene_manager_T* SCENE_MANAGER;

grid_T* init_grid()
{
    grid_T* grid = calloc(1, sizeof(struct GRID_STRUCT));

    for (int x = 0; x < WINDOW_WIDTH / 16; x++)
    {
        for (int y = 0; y < WINDOW_HEIGHT/ 16; y++)
        {
            grid->cells[x][y] = init_cell(16, 16);
        }
    }

    return grid;
}

void grid_tick(grid_T* grid)
{
    // just for the goofs and giggles, testing stuff
    for (int x = 0; x < WINDOW_WIDTH / 16; x++)
    {
        for (int y = 0; y < WINDOW_HEIGHT/ 16; y++)
        {
            cell_T* cell = grid->cells[x][y];

            if (random_int(0, 3) == 0)
            {
                if (!cell->selected)
                    cell->selected = 1;
                else
                    cell->selected = 0;
            }
        }
    }
}

void grid_draw(grid_T* grid)
{
    scene_T* scene = scene_manager_get_current_scene(SCENE_MANAGER);

    for (int x = 0; x < WINDOW_WIDTH / 16; x++)
    {
        for (int y = 0; y < WINDOW_HEIGHT/ 16; y++)
        {
            cell_T* cell = grid->cells[x][y];

            float cell_x = x * 16;
            float cell_y = y * 16;

            float r = 124.0f;
            float g = 111.0f;
            float b = 100.0f;

            // top
            draw_line(
                cell_x,
                cell_y,
                0.0f,
                cell_x + 16,
                cell_y,
                0.0f,
                r,
                g,
                b,
                scene->VAO,
                scene->camera->projection_view
            );

            // bottom
            draw_line(
                cell_x,
                cell_y + 16,
                0.0f,
                cell_x + 16,
                cell_y + 16,
                0.0f,
                r,
                g,
                b,
                scene->VAO,
                scene->camera->projection_view
            );

            // left
            draw_line(
                cell_x,
                cell_y,
                0.0f,
                cell_x,
                cell_y + 16,
                0.0f,
                r,
                g,
                b,
                scene->VAO,
                scene->camera->projection_view
            );

            // right
            draw_line(
                cell_x + 16,
                cell_y,
                0.0f,
                cell_x + 16,
                cell_y + 16,
                0.0f,
                r,
                g,
                b,
                scene->VAO,
                scene->camera->projection_view
            );

            if (cell->selected)
            {
                draw_2D_positioned_2D_mesh(
                    cell_x,
                    cell_y,
                    16,
                    16,
                    r,
                    g,
                    b,
                    scene->VAO,
                    scene->camera->projection_view
                );
            }
        }
    }
}