/**CFile***********************************************************************

  FileName    [mu_sym.cpp]

  Synopsis    [File for symmetry reduction]

  Author      [Igor Melatti]

  Copyright   [
  This file is part of the original verifier package of CMurphi. 
  Copyright (C) 2009-2012 by Sapienza University of Rome. 

  CMurphi is free software; you can redistribute it and/or 
  modify it under the terms of the GNU Lesser General Public 
  License as published by the Free Software Foundation; either 
  of the License, or (at your option) any later version.

  CMurphi is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public 
  License along with this library; if not, write to the Free Software 
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.

  To contact the CMurphi development board, email to <melatti@di.uniroma1.it>. ]

******************************************************************************/

void
 SymmetryClass::SetBestResult(int i, state * temp)
{
  if (!BestInitialized) {
    BestPermutedState = *temp;
    BestInitialized = TRUE;
  } else {
    switch (StateCmp(temp, &BestPermutedState)) {
    case -1:
      Perm.Add(i);
      BestPermutedState = *temp;
      break;
    case 1:
      Perm.Remove(i);
      break;
    case 0:
      // do nothing
      break;
    default:
      Error.Error("funny return value from StateCmp");
    }
  }
}

void state::Normalize()
{
  static SymmetryClass symmetry;

  symmetry.Normalize(this);
}

void state::MultisetSort()
{
  static SymmetryClass symmetry;

  symmetry.MultisetSort(this);
}
