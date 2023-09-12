/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_flags.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:29:17 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/22 19:14:33 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_FLAGS_H
# define EVENT_FLAGS_H

# define E_KEY_PRESS 2
# define E_KEY_RELEASE 3
# define E_BUTTON_PRESS 4
# define E_BUTTON_RELEASE 5
# define E_MOTION_NOTIFY 6
# define E_ENTER_NOTIFY 7
# define E_LEAVE_NOTIFY 8
# define E_FOCUS_IN 9
# define E_FOCUS_OUT 10
# define E_KEYMAP_NOTIFY 11
# define E_EXPOSE 12
# define E_GRAPHICS_EXPOSE 13
# define E_NO_EXPOSE 14
# define E_VISIBLITY_NOTIFY 15
# define E_CREATE_NOTIFY 16
# define E_DESTROY_NOTIFY 17
# define E_UNMAP_NOTIFY 18
# define E_MAP_NOTIFY 19
# define E_MAP_REQUEST 20
# define E_REPARENT_NOTIFY 21
# define E_CONFIGURE_NOTIFY 22
# define E_CONGIGURE_REQUEST 23
# define E_GRAVITY_NOTIFY 24
# define E_RESIZE_REQUEST 25
# define E_CIRCULATE_NOTIFY 26
# define E_CIRCULATE_REQUEST 27
# define E_PROPERTY_NOTIFY 28
# define E_SELECTION_CLEAR 29
# define E_SELECTION_REQUEST 30
# define E_SELECTION_NOTIFTY 31
# define E_COLORMAP_NOTIFY 32
# define E_CLIENT_MESSAGE 33
# define E_MAPPING_NOTIFY 34
# define E_GENERIC_EVENT 35
# define E_LAST_EVENT 36

# define M_NO_MASK 0L
# define M_KEY_PRESS 1L
# define M_KEY_RELEASE 2L
# define M_BUTTON_PRESS 4L
# define M_BUTTON_RELEASE 8L
# define M_WINDOW_ENTER 16L
# define M_WINDOW_LEAVE 32L
# define M_POINTER_MOTION 64L
# define M_POINTER_MOTION_HINT 128L
# define M_BUTTON_1_MOTION 256L
# define M_BUTTON_2_MOTION 512L
# define M_BUTTON_3_MOTION 1024L
# define M_BUTTON_4_MOTION 2048L
# define M_BUTTON_5_MOTION 4096L
# define M_BUTTON_MOTION 8192L
# define M_KEYMAP_STATE 16384L
# define M_EXPOSURE 32768L
# define M_VISIBILITY_CHANGE 65536L
# define M_STRUCTURE_NOTIFY 131072L
# define M_RESIZE_REDIRECT 262144L
# define M_SUBSTRUCTURE_NOTIFY 524288L
# define M_SUBSTRUCTURE_REDIRECT 1048576L
# define M_FOCUS_CHANGE 2097152L
# define M_PROPERTY_CHANGE 4194304L
# define M_COLORMAP_CHANGE 8388608L
# define M_OWNER_GRAB_BUTTON 16777216L

#endif /* EVENT_FLAGS_H */