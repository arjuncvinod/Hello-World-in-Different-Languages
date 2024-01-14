class TextEditor
  def initialize
    @text = ""
    @file_name = nil
  end

  def load_file(file_name)
    begin
      @text = File.read(file_name)
      @file_name = file_name
      puts "File loaded: #{@file_name}"
    rescue Errno::ENOENT
      puts "File not found: #{file_name}"
    end
  end

  def save_file
    return unless @file_name

    File.open(@file_name, 'w') do |file|
      file.puts @text
    end

    puts "File saved: #{@file_name}"
  end

  def edit
    puts "Text editor commands:"
    puts "  - Type your text to edit."
    puts "  - Type 'save' to save the file."
    puts "  - Type 'exit' to exit the editor."

    loop do
      print "> "
      input = gets.chomp

      case input
      when 'exit'
        break
      when 'save'
        save_file
      else
        @text << input << "\n"
      end
    end
  end
end

# Create a new text editor instance
editor = TextEditor.new

loop do
  puts "Text Editor Menu:"
  puts "  1. Load a file"
  puts "  2. Edit text"
  puts "  3. Exit"

  print "Select an option: "
  choice = gets.chomp.to_i

  case choice
  when 1
    print "Enter the file name to load: "
    file_name = gets.chomp
    editor.load_file(file_name)
  when 2
    editor.edit
  when 3
    break
  else
    puts "Invalid option. Please try again."
  end
end
