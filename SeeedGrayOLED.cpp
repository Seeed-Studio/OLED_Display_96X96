/*
 * SeeedGrayOLED.cpp
 * SSD1327 Gray OLED Driver Library
 *
 * Copyright (c) 2011 seeed technology inc.
 * Author        :   Visweswara R
 * Create Time   :   Dec 2011
 * Change Log    :
 *
 * GNU GENERAL PUBLIC LICENSE
 * Version 2, June 1991
 * Copyright (C) 1989, 1991 Free Software Foundation, Inc. 
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * Preamble
 * The licenses for most software are designed to take away your freedom to share and change it. 
 * By contrast, the GNU General Public License is intended to guarantee your freedom to share and 
 * change free software--to make sure the software is free for all its users. This General Public 
 * License applies to most of the Free Software Foundation's software and to any other program whose 
 * authors commit to using it. (Some other Free Software Foundation software is covered by the GNU 
 * Lesser General Public License instead.) You can apply it to your programs, too.
 *
 * When we speak of free software, we are referring to freedom, not price. Our General Public Licenses
 * are designed to make sure that you have the freedom to distribute copies of free software (and charge
 * for this service if you wish), that you receive source code or can get it if you want it, that you 
 * can change the software or use pieces of it in new free programs; and that you know you can do these things.
 *
 * To protect your rights, we need to make restrictions that forbid anyone to deny you these rights or to 
 * ask you to surrender the rights. These restrictions translate to certain responsibilities for you if you
 * distribute copies of the software, or if you modify it.
 *
 * For example, if you distribute copies of such a program, whether gratis or for a fee, you must give the 
 * recipients all the rights that you have. You must make sure that they, too, receive or can get the source
 * code. And you must show them these terms so they know their rights.
 *
 * We protect your rights with two steps: (1) copyright the software, and (2) offer you this license which 
 * gives you legal permission to copy, distribute and/or modify the software.
 *
 * Also, for each author's protection and ours, we want to make certain that everyone understands that there 
 * is no warranty for this free software. If the software is modified by someone else and passed on, we want
 * its recipients to know that what they have is not the original, so that any problems introduced by others 
 * will not reflect on the original authors' reputations.
 *
 * Finally, any free program is threatened constantly by software patents. We wish to avoid the danger that 
 * redistributors of a free program will individually obtain patent licenses, in effect making the program 
 * proprietary. To prevent this, we have made it clear that any patent must be licensed for everyone's free 
 * use or not licensed at all.
 *
 * The precise terms and conditions for copying, distribution and modification follow.
 *
 * TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 * 0. This License applies to any program or other work which contains a notice placed by the copyright holder
 * saying it may be distributed under the terms of this General Public License. The "Program", below, refers to 
 * any such program or work, and a "work based on the Program" means either the Program or any derivative work 
 * under copyright law: that is to say, a work containing the Program or a portion of it, either verbatim or 
 * with modifications and/or translated into another language. (Hereinafter, translation is included without 
 * limitation in the term "modification".) Each licensee is addressed as "you".
 *
 * Activities other than copying, distribution and modification are not covered by this License; they are outside
 * its scope. The act of running the Program is not restricted, and the output from the Program is covered only 
 * if its contents constitute a work based on the Program (independent of having been made by running the Program).
 * Whether that is true depends on what the Program does.
 *
 * 1. You may copy and distribute verbatim copies of the Program's source code as you receive it, in any medium, 
 * provided that you conspicuously and appropriately publish on each copy an appropriate copyright notice and 
 * disclaimer of warranty; keep intact all the notices that refer to this License and to the absence of any warranty;
 * and give any other recipients of the Program a copy of this License along with the Program.
 *
 * You may charge a fee for the physical act of transferring a copy, and you may at your option offer warranty 
 * protection in exchange for a fee.
 *
 * 2. You may modify your copy or copies of the Program or any portion of it, thus forming a work based on the Program,
 * and copy and distribute such modifications or work under the terms of Section 1 above, provided that you also meet 
 * all of these conditions:
 *
 * a) You must cause the modified files to carry prominent notices stating that you changed the files and the date of any change.
 * b) You must cause any work that you distribute or publish, that in whole or in part contains or is derived from the 
 * Program or any part thereof, to be licensed as a whole at no charge to all third parties under the terms of this License.
 * c) If the modified program normally reads commands interactively when run, you must cause it, when started running for such 
 * interactive use in the most ordinary way, to print or display an announcement including an appropriate copyright notice and 
 * a notice that there is no warranty (or else, saying that you provide a warranty) and that users may redistribute the program 
 * under these conditions, and telling the user how to view a copy of this License. (Exception: if the Program itself is interactive
 * but does not normally print such an announcement, your work based on the Program is not required to print an announcement.)
 * These requirements apply to the modified work as a whole. If identifiable sections of that work are not derived from the Program, 
 * and can be reasonably considered independent and separate works in themselves, then this License, and its terms, do not apply to 
 * those sections when you distribute them as separate works. But when you distribute the same sections as part of a whole which is 
 * a work based on the Program, the distribution of the whole must be on the terms of this License, whose permissions for other licensees
 * extend to the entire whole, and thus to each and every part regardless of who wrote it.
 *
 * Thus, it is not the intent of this section to claim rights or contest your rights to work written entirely by you; rather, the intent 
 * is to exercise the right to control the distribution of derivative or collective works based on the Program.
 *
 * In addition, mere aggregation of another work not based on the Program with the Program (or with a work based on the Program) on a volume
 * of a storage or distribution medium does not bring the other work under the scope of this License.
 *
 * 3. You may copy and distribute the Program (or a work based on it, under Section 2) in object code or executable form under the terms of 
 * Sections 1 and 2 above provided that you also do one of the following:
 *
 * a) Accompany it with the complete corresponding machine-readable source code, which must be distributed under the terms of Sections 
 * 1 and 2 above on a medium customarily used for software interchange; or,
 * b) Accompany it with a written offer, valid for at least three years, to give any third party, for a charge no more than your cost 
 * of physically performing source distribution, a complete machine-readable copy of the corresponding source code, to be distributed 
 * under the terms of Sections 1 and 2 above on a medium customarily used for software interchange; or,
 * c) Accompany it with the information you received as to the offer to distribute corresponding source code. (This alternative is allowed 
 * only for noncommercial distribution and only if you received the program in object code or executable form with such an offer, in accord 
 * with Subsection b above.)
 * The source code for a work means the preferred form of the work for making modifications to it. For an executable work, complete source 
 * code means all the source code for all modules it contains, plus any associated interface definition files, plus the scripts used to control 
 * compilation and installation of the executable. However, as a special exception, the source code distributed need not include anything that
 * is normally distributed (in either source or binary form) with the major components (compiler, kernel, and so on) of the operating system on 
 * which the executable runs, unless that component itself accompanies the executable.
 *
 * If distribution of executable or object code is made by offering access to copy from a designated place, then offering equivalent access to 
 * copy the source code from the same place counts as distribution of the source code, even though third parties are not compelled to copy the 
 * source along with the object code.
 *
 * 4. You may not copy, modify, sublicense, or distribute the Program except as expressly provided under this License. Any attempt otherwise to 
 * copy, modify, sublicense or distribute the Program is void, and will automatically terminate your rights under this License. However, parties 
 * who have received copies, or rights, from you under this License will not have their licenses terminated so long as such parties remain in full 
 * compliance.
 *
 * 5. You are not required to accept this License, since you have not signed it. However, nothing else grants you permission to modify or distribute
 * the Program or its derivative works. These actions are prohibited by law if you do not accept this License. Therefore, by modifying or distributing
 * the Program (or any work based on the Program), you indicate your acceptance of this License to do so, and all its terms and conditions for copying,
 * distributing or modifying the Program or works based on it.
 *
 * 6. Each time you redistribute the Program (or any work based on the Program), the recipient automatically receives a license from the original licensor
 * to copy, distribute or modify the Program subject to these terms and conditions. You may not impose any further restrictions on the recipients' exercise 
 * of the rights granted herein. You are not responsible for enforcing compliance by third parties to this License.
 *
 * 7. If, as a consequence of a court judgment or allegation of patent infringement or for any other reason (not limited to patent issues), conditions are 
 * imposed on you (whether by court order, agreement or otherwise) that contradict the conditions of this License, they do not excuse you from the conditions 
 * of this License. If you cannot distribute so as to satisfy simultaneously your obligations under this License and any other pertinent obligations, then 
 * as a consequence you may not distribute the Program at all. For example, if a patent license would not permit royalty-free redistribution of the Program 
 * by all those who receive copies directly or indirectly through you, then the only way you could satisfy both it and this License would be to refrain entirely
 * from distribution of the Program.
 *
 * If any portion of this section is held invalid or unenforceable under any particular circumstance, the balance of the section is intended to apply and the 
 * section as a whole is intended to apply in other circumstances.
 *
 * It is not the purpose of this section to induce you to infringe any patents or other property right claims or to contest validity of any such claims; this 
 * section has the sole purpose of protecting the integrity of the free software distribution system, which is implemented by public license practices. Many 
 * people have made generous contributions to the wide range of software distributed through that system in reliance on consistent application of that system; 
 * it is up to the author/donor to decide if he or she is willing to distribute software through any other system and a licensee cannot impose that choice.
 *
 * This section is intended to make thoroughly clear what is believed to be a consequence of the rest of this License.
 *
 * 8. If the distribution and/or use of the Program is restricted in certain countries either by patents or by copyrighted interfaces, the original copyright 
 * holder who places the Program under this License may add an explicit geographical distribution limitation excluding those countries, so that distribution 
 * is permitted only in or among countries not thus excluded. In such case, this License incorporates the limitation as if written in the body of this License.
 *
 * 9. The Free Software Foundation may publish revised and/or new versions of the General Public License from time to time. Such new versions will be similar in 
 * spirit to the present version, but may differ in detail to address new problems or concerns.
 * 
 * Each version is given a distinguishing version number. If the Program specifies a version number of this License which applies to it and "any later version",
 * you have the option of following the terms and conditions either of that version or of any later version published by the Free Software Foundation. If the 
 * Program does not specify a version number of this License, you may choose any version ever published by the Free Software Foundation.
 *
 * 10. If you wish to incorporate parts of the Program into other free programs whose distribution conditions are different, write to the author to ask for permission.
 * For software which is copyrighted by the Free Software Foundation, write to the Free Software Foundation; we sometimes make exceptions for this. Our decision will 
 * be guided by the two goals of preserving the free status of all derivatives of our free software and of promoting the sharing and reuse of software generally.
 *
 * NO WARRANTY
 *
 * 11. BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED
 * IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS 
 * WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 * 12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR REDISTRIBUTE THE 
 * PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY 
 * TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE 
 * PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 */

#include "Arduino.h"

//#include "WProgram.h"
#include "Wire.h"

#include "SeeedGrayOLED.h"

#include <avr/pgmspace.h>

// 8x8 Font ASCII 32 - 127 Implemented
// Users can modify this to support more characters(glyphs)
// BasicFont is placed in code memory.

// This font can be freely used without any restriction(It is placed in public domain)
const unsigned char BasicFont[][8] PROGMEM=
{
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x5F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x07,0x00,0x07,0x00,0x00,0x00},
  {0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00},
  {0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00},
  {0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00},
  {0x00,0x36,0x49,0x55,0x22,0x50,0x00,0x00},
  {0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00},
  {0x00,0x1C,0x22,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x22,0x1C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x2A,0x1C,0x2A,0x08,0x00,0x00},
  {0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00},
  {0x00,0xA0,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
  {0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00},
  {0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00},
  {0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00},
  {0x00,0x62,0x51,0x49,0x49,0x46,0x00,0x00},
  {0x00,0x22,0x41,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00},
  {0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00},
  {0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00},
  {0x00,0x01,0x71,0x09,0x05,0x03,0x00,0x00},
  {0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00},
  {0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00},
  {0x00,0x00,0xAC,0x6C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00},
  {0x00,0x14,0x14,0x14,0x14,0x14,0x00,0x00},
  {0x00,0x41,0x22,0x14,0x08,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00},
  {0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00},
  {0x00,0x7E,0x09,0x09,0x09,0x7E,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x22,0x1C,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x41,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x51,0x72,0x00,0x00},
  {0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00},
  {0x00,0x41,0x7F,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00},
  {0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00},
  {0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00},
  {0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00},
  {0x00,0x7F,0x04,0x08,0x10,0x7F,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00},
  {0x00,0x3E,0x41,0x51,0x21,0x5E,0x00,0x00},
  {0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00},
  {0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00},
  {0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00},
  {0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00},
  {0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00},
  {0x00,0x3F,0x40,0x38,0x40,0x3F,0x00,0x00},
  {0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00},
  {0x00,0x03,0x04,0x78,0x04,0x03,0x00,0x00},
  {0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x04,0x08,0x10,0x20,0x00,0x00},
  {0x00,0x41,0x41,0x7F,0x00,0x00,0x00,0x00},
  {0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00},
  {0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00},
  {0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00},
  {0x00,0x7F,0x48,0x44,0x44,0x38,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x28,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00},
  {0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00},
  {0x00,0x08,0x7E,0x09,0x02,0x00,0x00,0x00},
  {0x00,0x18,0xA4,0xA4,0xA4,0x7C,0x00,0x00},
  {0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00},
  {0x00,0x00,0x7D,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x80,0x84,0x7D,0x00,0x00,0x00,0x00},
  {0x00,0x7F,0x10,0x28,0x44,0x00,0x00,0x00},
  {0x00,0x41,0x7F,0x40,0x00,0x00,0x00,0x00},
  {0x00,0x7C,0x04,0x18,0x04,0x78,0x00,0x00},
  {0x00,0x7C,0x08,0x04,0x7C,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x38,0x00,0x00,0x00},
  {0x00,0xFC,0x24,0x24,0x18,0x00,0x00,0x00},
  {0x00,0x18,0x24,0x24,0xFC,0x00,0x00,0x00},
  {0x00,0x00,0x7C,0x08,0x04,0x00,0x00,0x00},
  {0x00,0x48,0x54,0x54,0x24,0x00,0x00,0x00},
  {0x00,0x04,0x7F,0x44,0x00,0x00,0x00,0x00},
  {0x00,0x3C,0x40,0x40,0x7C,0x00,0x00,0x00},
  {0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00},
  {0x00,0x3C,0x40,0x30,0x40,0x3C,0x00,0x00},
  {0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00},
  {0x00,0x1C,0xA0,0xA0,0x7C,0x00,0x00,0x00},
  {0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00},
  {0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x36,0x08,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x01,0x02,0x01,0x00,0x00},
  {0x00,0x02,0x05,0x05,0x02,0x00,0x00,0x00} 
};

void SeeedGrayOLED::init(void)
{
    sendCommand(0xFD); // Unlock OLED driver IC MCU interface from entering command. i.e: Accept commands
    sendCommand(0x12);
    sendCommand(0xAE); // Set display off
    sendCommand(0xA8); // set multiplex ratio
    sendCommand(0x5F); // 96
    sendCommand(0xA1); // set display start line
    sendCommand(0x00);
    sendCommand(0xA2); // set display offset
    sendCommand(0x60);
    sendCommand(0xA0); // set remap
    sendCommand(0x46);
    sendCommand(0xAB); // set vdd internal
    sendCommand(0x01); //
    sendCommand(0x81); // set contrasr
    sendCommand(0x53); // 100 nit
    sendCommand(0xB1); // Set Phase Length
    sendCommand(0X51); //
    sendCommand(0xB3); // Set Display Clock Divide Ratio/Oscillator Frequency
    sendCommand(0x01);
    sendCommand(0xB9); //
    sendCommand(0xBC); // set pre_charge voltage/VCOMH
    sendCommand(0x08); // (0x08);
    sendCommand(0xBE); // set VCOMH
    sendCommand(0X07); // (0x07);
    sendCommand(0xB6); // Set second pre-charge period
    sendCommand(0x01); //
    sendCommand(0xD5); // enable second precharge and enternal vsl
    sendCommand(0X62); // (0x62);
    sendCommand(0xA4); // Set Normal Display Mode
    sendCommand(0x2E); // Deactivate Scroll
    sendCommand(0xAF); // Switch on display
    delay(100);

    // Row Address
    sendCommand(0x75);    // Set Row Address 
    sendCommand(0x00);    // Start 0
    sendCommand(0x5f);    // End 95 


    // Column Address
    sendCommand(0x15);    // Set Column Address 
    sendCommand(0x08);    // Start from 8th Column of driver IC. This is 0th Column for OLED 
    sendCommand(0x37);    // End at  (8 + 47)th column. Each Column has 2 pixels(segments)

    // Init gray level for text. Default:Brightest White
    grayH= 0xF0;
    grayL= 0x0F;
}

void SeeedGrayOLED::sendCommand(unsigned char command)
{
    Wire.beginTransmission(SeeedGrayOLED_Address); // begin I2C communication
    Wire.write(SeeedGrayOLED_Command_Mode);    // Set OLED Command mode
    Wire.write(command);
    Wire.endTransmission();                    // End I2C communication
}

void SeeedGrayOLED::setContrastLevel(unsigned char ContrastLevel)
{
    sendCommand(SeeedGrayOLED_Set_ContrastLevel_Cmd);
    sendCommand(ContrastLevel);
}

void SeeedGrayOLED::setHorizontalMode()
{
    sendCommand(0xA0); // remap to
    sendCommand(0x42); // horizontal mode

    // Row Address
    sendCommand(0x75);    // Set Row Address 
    sendCommand(0x00);    // Start 0
    sendCommand(0x5f);    // End 95 

    // Column Address
    sendCommand(0x15);    // Set Column Address 
    sendCommand(0x08);    // Start from 8th Column of driver IC. This is 0th Column for OLED 
    sendCommand(0x37);    // End at  (8 + 47)th column. Each Column has 2 pixels(or segments)
}

void SeeedGrayOLED::setVerticalMode()
{
    sendCommand(0xA0); // remap to
    sendCommand(0x46); // Vertical mode
}

void SeeedGrayOLED::setTextXY(unsigned char Row, unsigned char Column)
{
    //Column Address
    sendCommand(0x15);             /* Set Column Address */
    sendCommand(0x08+(Column*4));  /* Start Column: Start from 8 */
    sendCommand(0x37);             /* End Column */
    // Row Address
    sendCommand(0x75);             /* Set Row Address */
    sendCommand(0x00+(Row*8));     /* Start Row*/
    sendCommand(0x07+(Row*8));     /* End Row*/
}

void SeeedGrayOLED::clearDisplay()
{
    unsigned char i,j;
    for(j=0;j<48;j++)
    {
        for(i=0;i<96;i++)  //clear all columns
        {
            sendData(0x00);
        }
    }

}

void SeeedGrayOLED::sendData(unsigned char Data)
{
    Wire.beginTransmission(SeeedGrayOLED_Address); // begin I2C transmission
    Wire.write(SeeedGrayOLED_Data_Mode);            // data mode
    Wire.write(Data);
    Wire.endTransmission();                    // stop I2C transmission
}

void SeeedGrayOLED::setGrayLevel(unsigned char grayLevel)
{
    grayH = (grayLevel << 4) & 0xF0;
    grayL =  grayLevel & 0x0F;
}

void SeeedGrayOLED::putChar(unsigned char C)
{
    if(C < 32 || C > 127) //Ignore non-printable ASCII characters. This can be modified for multilingual font.
    {
        C=' '; //Space
    }   

    
    for(char i=0;i<8;i=i+2)
    {
        for(char j=0;j<8;j++)
        {
            // Character is constructed two pixel at a time using vertical mode from the default 8x8 font
            char c=0x00;
            char bit1=(pgm_read_byte(&BasicFont[C-32][i]) >> j)  & 0x01;  
            char bit2=(pgm_read_byte(&BasicFont[C-32][i+1]) >> j) & 0x01;
           // Each bit is changed to a nibble
            c|=(bit1)?grayH:0x00;
            c|=(bit2)?grayL:0x00;
            sendData(c);
        }
    }
}

void SeeedGrayOLED::putString(const char *String)
{
    unsigned char i=0;
    while(String[i])
    {
        putChar(String[i]);     
        i++;
    }
}

unsigned char SeeedGrayOLED::putNumber(long long_num)
{
    unsigned char char_buffer[10]="";
    unsigned char i = 0;
    unsigned char f = 0;

    if (long_num < 0)
    {
        f=1;
        putChar('-');
        long_num = -long_num;
    }
    else if (long_num == 0)
    {
        f=1;
        putChar('0');
        return f;
    }

    while (long_num > 0)
    {
        char_buffer[i++] = long_num % 10;
        long_num /= 10;
    }

    f=f+i;
    for(; i > 0; i--)
    {
        putChar('0'+ char_buffer[i - 1]);
    }
    return f;

}



void SeeedGrayOLED::drawBitmap(unsigned char *bitmaparray,int bytes)
{
    char localAddressMode = addressingMode;
    if(addressingMode != HORIZONTAL_MODE)
    {
        //Bitmap is drawn in horizontal mode
        setHorizontalMode();
    }

    for(int i=0;i<bytes;i++)
    {

    for(int j=0;j<8;j=j+2) 
    {
        char c=0x00;
        char bit1=pgm_read_byte(&bitmaparray[i]) << j  & 0x80;  
        char bit2=pgm_read_byte(&bitmaparray[i]) << (j+1) & 0x80;

        // Each bit is changed to a nibble
        c|=(bit1)?grayH:0x00;
        // Each bit is changed to a nibble
        c|=(bit2)?grayL:0x00;
        sendData(c);
     }
    }
    if(localAddressMode == VERTICAL_MODE)
    {
        //If Vertical Mode was used earlier, restore it.
        setVerticalMode();
    }

}

void SeeedGrayOLED::setHorizontalScrollProperties(bool direction,unsigned char startRow, unsigned char endRow,unsigned char startColumn, unsigned char endColumn, unsigned char scrollSpeed)
{
    /*
Use the following defines for 'direction' :

 Scroll_Left            
 Scroll_Right           

Use the following defines for 'scrollSpeed' :

 Scroll_2Frames     
 Scroll_3Frames
 Scroll_4Frames
 Scroll_5Frames 
 Scroll_25Frames
 Scroll_64Frames
 Scroll_128Frames
 Scroll_256Frames

*/

    if(Scroll_Right == direction)
    {
        //Scroll Right
        sendCommand(0x27);
    }
    else
    {
        //Scroll Left  
        sendCommand(0x26);
    }
    sendCommand(0x00);       //Dummmy byte
    sendCommand(startRow);
    sendCommand(scrollSpeed);
    sendCommand(endRow);
    sendCommand(startColumn+8);
    sendCommand(endColumn+8);
    sendCommand(0x00);      //Dummmy byte

}

void SeeedGrayOLED::activateScroll()
{
    sendCommand(SeeedGrayOLED_Activate_Scroll_Cmd);
}

void SeeedGrayOLED::deactivateScroll()
{
    sendCommand(SeeedGrayOLED_Dectivate_Scroll_Cmd);
}

void SeeedGrayOLED::setNormalDisplay()
{
    sendCommand(SeeedGrayOLED_Normal_Display_Cmd);
}

void SeeedGrayOLED::setInverseDisplay()
{
    sendCommand(SeeedGrayOLED_Inverse_Display_Cmd);
}

SeeedGrayOLED SeeedGrayOled;  // Preinstantiate Objects

