// void validatePhoneNumber(String pNumber) {
//     // 1st Case - +91 9765463742 have to check for + sign
//     boolean flag = false;
//     int index;
//     String specialCharacter = "!@#$%^&*()-/`~:<>/?|=.,";
//     if (pNumber.startsWith("+") && pNumber.length() == 14) {
//         for (index = 1; index < pNumber.length(); index++) {
//             if (!(Character.isDigit(pNumber.charAt(index)) || Character.isSpaceChar(pNumber.charAt(index)))
//                     && (specialCharacter.contains(Character.toString(pNumber.charAt(index)))
//                             || Character.isLetter(pNumber.charAt(index)))) {
//                 flag = true;
//                 break;
//             }
//         }
//     } else {
//         flag = true;
//     }
//     if (!flag) {
//         System.out.println("Number " + pNumber + " is Valid");
//     } else {
//         System.out.println(pNumber + " Number is Invalid");
//     }
// }

