/*
 * @(#)Phrase.h 3.00 14 May 1999
 *
 * Copyright (c) 2000 Pete Goodliffe (pete@cthree.org)
 *
 * This file is part of TSE3 - the Trax Sequencer Engine version 3.00.
 *
 * This library is modifiable/redistributable under the terms of the GNU
 * General Public License.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; see the file COPYING. If not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef TSE3_PHRASE_H
#define TSE3_PHRASE_H

#include "tse3/listen/Phrase.h"

#include "tse3/Notifier.h"
#include "tse3/MidiData.h"
#include "tse3/Serializable.h"
#include "tse3/DisplayParams.h"

#include <string>

namespace TSE3
{
    class PhraseList;

    /**
     * The Phrase class is a @ref MidiData object with a unique reference name.
     *
     * Phrases are held in a @ref PhraseList. This @ref PhraseList is the
     * context of the unique name - there can be two @ref Song objects which
     * have Phrases with the same name, but you can't have two Phrases with the
     * same name in one @ref PhraseList.
     *
     * Phrases are only generated by @ref PhraseEdit objects (see
     * @ref PhraseEdit::createPhrase() for details).
     *
     * Phrases are used in a @ref Part to produce MIDI data in the @ref Song.
     *
     * The Phrase has a @ref DisplayParameters object associated with it which
     * may be used by an application to redraw the Phrase in any @ref Part on
     * screen (this use is optional). If you use this, a @ref Part
     * @ref DisplayParams should superceed any @ref Phrase @ref DisplayParams.
     *
     * @sect Command classes
     *
     * Use the following command classes to manipute this object in a undo/redo
     * environment.
     *
     *     @li @ref TSE3::Cmd::Phrase_SetInfo
     *     @li @ref TSE3::Cmd::Phrase_Create
     *     @li @ref TSE3::Cmd::Phrase_Erase
     *     @li @ref TSE3::Cmd::Phrase_Replace
     *     @li @ref TSE3::Cmd::Part_SetInfo
     *     @li @ref TSE3::Cmd::Part_SetPhrase
     *
     * @short   A list of MidiEvents with unique reference name
     * @author  Pete Goodliffe
     * @version 3.00
     * @see     MidiData
     * @see     PhraseList
     */
    class Phrase : public MidiData,
                   public Serializable,
                   public Listener<DisplayParamsListener>,
                   public Notifier<PhraseListener>
    {
        public:

            virtual ~Phrase();

            /**
             * Returns a pointer to the parent @ref PhraseList that this
             * Phrase has been inserted into. If this Phrase has not been
             * inserted in a @ref PhraseList, this method returns zero.
             *
             * @return @ref PhraseList this Phrase is inserted in
             */
            PhraseList *parent() const { return _parent; }

            /**
             * Returns the unique title of this Phrase.
             *
             * @return Phrase's title
             * @see    setTitle
             */
            const std::string &title() const { return _title; }

            /**
             * Sets the unique Phrase title. Since the Phrase is held in a
             * @ref PhraseList, the new name must be unique in this list.
             * If it is not, a @ref PhrseListError is thrown and the name
             * is not changed.
             *
             * @param  title New Phrase title
             * @throws PhraseListError
             * @see    title
             */
            void setTitle(const std::string &title);

            /**
             * The display parameters.
             *
             * @return The Part's @ref DisplayParams object
             */
            DisplayParams *displayParams() { return &_display; }

            /**
             * This operator works on the value of the title alone
             */
            int operator<(const Phrase &p) const { return _title < p._title; }

            /**
             * This operator works on the value of the title alone
             */
            int operator==(const Phrase &p) const { return _title == p._title; }

            /**
             * @reimplemented
             *
             * Implementation of the @ref Serializable interface
             *
             * NB: Loading is done by the @ref PhraseList. A Phrase can't be
             * altered so it can't logically load itself. Sigh.
             */
            virtual void save(std::ostream &o, int i) const;

            /**
             * The @ref PhraseEdit class is a friend of Phrase - it is the
             * only type of object that can create Phrases.
             */
            friend class PhraseEdit;

            /**
             * The @ref PhraseList class is a friend so that it can access the
             * @ref setParent() method.
             */
            friend class PhraseList;

            /**
             * @reimplemented
             */
            virtual void DisplayParams_Altered(DisplayParams *);

        private:

            Phrase(const int noEvents);
            Phrase(const Phrase &);
            Phrase &operator=(const Phrase &);

            /**
             * This method is called by the @ref PhraseList class alone. It is
             * used to set the parent @ref PhraseList pointer, song. This will
             * be set to the parent's pointer, or to zero if the Phrase is
             * removed from the @ref PhraseList.
             *
             * This is the only private member the @ref PhraseList class
             * accesses.
             *
             * @ref parent @ref PhraseList object that this Phrase has been
             *             inserted into.
             */
            void setParent(PhraseList *parent);

            std::string    _title;
            DisplayParams  _display;
            PhraseList    *_parent;
    };
}

#endif
