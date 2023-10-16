public class CapitalizeFirstLetter {
    public static void main(String[] args) {
        String sentence = "hello hackers! welcome to hacktoberfest 2023";
        String capitalized = capitalizeFirstLetter(sentence);
        System.out.println(capitalized);
    }

    public static String capitalizeFirstLetter(String input) {
        if (input == null || input.isEmpty()) {
            return input;
        }

        String[] words = input.split("\\s"); // Split the input string into words
        StringBuilder result = new StringBuilder();

        for (String word : words) {
            if (word.length() > 0) {
                // Capitalize the first letter of the word and append the rest of the word
                result.append(Character.toUpperCase(word.charAt(0)));
                if (word.length() > 1) {
                    result.append(word.substring(1));
                }
                result.append(" ");
            }
        }
        return result.toString();
    }
}
