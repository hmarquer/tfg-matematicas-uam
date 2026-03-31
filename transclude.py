import re
import sys
import argparse
import textwrap
from pathlib import Path

def normalize_block_indentation(text: str) -> str:
    """Elimina sangria comun y lineas vacias externas de un bloque."""
    lines = text.splitlines()

    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()

    if not lines:
        return ""

    return textwrap.dedent("\n".join(lines))


def get_note_content(note_name: str, tag: str, base_dir: Path) -> str:
    """Extrae el contenido de la nota entre %<*tag> y %</tag>."""
    # Asumimos que las notas tienen extensión .tex, ajusta si es diferente
    note_path = base_dir / f"{note_name}.tex"
    
    if not note_path.exists():
        # Si no se encuentra con .tex, probar sin extensión o tal cual
        note_path = base_dir / note_name
        if not note_path.exists():
            return f"% Error: No se encontró la nota '{note_name}'"
            
    content = note_path.read_text(encoding='utf-8')
    
    # Imita \ExecuteMetaData: usa el tag opcional de \transclude (por defecto, note)
    escaped_tag = re.escape(tag)
    pattern = re.compile(
        rf'^\s*%<\*{escaped_tag}>\s*$\n?(.*?)\n?^\s*%</{escaped_tag}>\s*$',
        flags=re.DOTALL | re.MULTILINE,
    )
    match = pattern.search(content)
    
    if match:
        return normalize_block_indentation(match.group(1))
    
    return f"% Error: No se encontraron las etiquetas %<*{tag}> y %</{tag}> en el archivo '{note_path}'"

def process_file(file_path: Path, base_dir: Path, in_place: bool = False):
    """Procesa un archivo reemplazando los \\transclude{}"""
    content = file_path.read_text(encoding='utf-8')
    
    def replacer(match):
        indent = match.group(1)
        tag = match.group(2) or "note"
        note_name = match.group(3)
        
        # Extraer contenido de la nota
        note_content = get_note_content(note_name, tag, base_dir)
        
        # Separar en líneas para aplicar la indentación
        lines = note_content.split('\n')
        
        if not lines:
            return ""
            
        # Se aplica solo la sangria del punto de insercion, no la interna del documento fuente.
        indented_lines = [f"{indent}{line}" if line else "" for line in lines]
        
        return '\n'.join(indented_lines)

    # Coincide con espacios al inicio de la línea + \transclude{nombre_nota} o \transclude[opcional]{nombre_nota}
    pattern = re.compile(r'^([ \t]*)\\transclude(?:\[([^\]]+)\])?\{([^}]+)\}', flags=re.MULTILINE)
    
    new_content = pattern.sub(replacer, content)
    
    if in_place:
        file_path.write_text(new_content, encoding='utf-8')
        print(f"Archivo actualizado: {file_path}")
    else:
        print(new_content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Reemplaza \\transclude{nota} con el contenido de las notas.")
    parser.add_argument("file", type=str, help="Archivo a procesar")
    parser.add_argument("-d", "--dir", type=str, default=".", help="Directorio base donde buscar las notas")
    parser.add_argument("-i", "--in-place", action="store_true", help="Sobrescribir el archivo original")
    
    args = parser.parse_args()
    
    target_file = Path(args.file)
    base_dir = Path(args.dir)
    
    if not target_file.exists():
        print(f"Error: El archivo {target_file} no existe.")
        sys.exit(1)
        
    process_file(target_file, base_dir, args.in_place)
