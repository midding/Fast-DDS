// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <fastrtps/types/DynamicDataHelper.hpp>
#include <fastrtps/types/MemberDescriptor.h>

using namespace eprosima::fastrtps::types;

void DynamicDataHelper::print(
        const DynamicData_ptr& data)
{
    print(data.get());
}

std::ostream& DynamicDataHelper::print(
        std::ostream& output,
        const DynamicData_ptr& data)
{
    return print(output, data.get());
}

void DynamicDataHelper::print(
        const DynamicData* data)
{
    if (nullptr != data)
    {
        switch (data->type_->get_kind())
        {
            case TK_STRUCTURE:
            {
                std::map<MemberId, DynamicTypeMember*> members;
                data->type_->get_all_members(members);
                for (auto it : members)
                {
                    print_member(const_cast<DynamicData*>(data), it.second);
                }
                break;
            }
            default:
            {
                std::cout << "Only structs are supported by DynamicDataHelper::print method." << std::endl;
            }
        }
    }
    else
    {
        std::cout << "<NULL>" << std::endl;
    }
}

std::ostream& DynamicDataHelper::print(
        std::ostream& output,
        const DynamicData* data)
{
    if (nullptr != data)
    {
        switch (data->type_->get_kind())
        {
            case TK_STRUCTURE:
            {
                std::map<MemberId, DynamicTypeMember*> members;
                data->type_->get_all_members(members);
                for (auto it : members)
                {
                    print_member(const_cast<DynamicData*>(data), output, it.second);
                }
                break;
            }
            default:
            {
                output << "Only structs are supported by DynamicDataHelper::print method.\n";
            }
        }
    }
    else
    {
        output << "<NULL>\n";
    }
    return output;
}

void DynamicDataHelper::print_basic_element(
        DynamicData* data,
        MemberId id,
        TypeKind kind)
{
    switch (kind)
    {
        case TK_NONE:
        {
            std::cout << "<type not defined!>";
            break;
        }
        case TK_BOOLEAN:
        {
            std::cout << (data->get_bool_value(id) ? "true" : "false");
            break;
        }
        case TK_BYTE:
        {
            std::cout << static_cast<uint32_t>(data->get_byte_value(id));
            break;
        }
        case TK_INT16:
        {
            std::cout << data->get_int16_value(id);
            break;
        }
        case TK_INT32:
        {
            std::cout << data->get_int32_value(id);
            break;
        }
        case TK_INT64:
        {
            std::cout << data->get_int64_value(id);
            break;
        }
        case TK_UINT16:
        {
            std::cout << data->get_uint16_value(id);
            break;
        }
        case TK_UINT32:
        {
            std::cout << data->get_uint32_value(id);
            break;
        }
        case TK_UINT64:
        {
            std::cout << data->get_uint64_value(id);
            break;
        }
        case TK_FLOAT32:
        {
            std::cout << data->get_float32_value(id);
            break;
        }
        case TK_FLOAT64:
        {
            std::cout << data->get_float64_value(id);
            break;
        }
        case TK_FLOAT128:
        {
            std::cout << data->get_float128_value(id);
            break;
        }
        case TK_CHAR8:
        {
            std::cout << data->get_char8_value(id);
            break;
        }
        case TK_CHAR16:
        {
            std::cout << data->get_char16_value(id);
            break;
        }
        case TK_STRING8:
        {
            std::cout << data->get_string_value(id);
            break;
        }
        case TK_STRING16:
        {
            std::wcout << data->get_wstring_value(id);
            break;
        }
        case TK_BITMASK:
        {
            size_t size = data->type_->get_size();
            switch (size)
            {
                case 1: std::cout << data->get_uint8_value(id); break;
                case 2: std::cout << data->get_uint16_value(id); break;
                case 3: std::cout << data->get_uint32_value(id); break;
                case 4: std::cout << data->get_uint64_value(id); break;
            }
            break;
        }
        case TK_ENUM:
        {
            std::cout << data->get_uint32_value(id);
            break;
        }
        default:
            break;
    }
}

void DynamicDataHelper::print_basic_element(
        DynamicData* data,
        MemberId id,
        TypeKind kind,
        std::ostream& output)
{
    switch (kind)
    {
        case TK_NONE:
        {
            output << "<type not defined!>";
            break;
        }
        case TK_BOOLEAN:
        {
            output << (data->get_bool_value(id) ? "true" : "false");
            break;
        }
        case TK_BYTE:
        {
            output << std::to_string(static_cast<uint32_t>(data->get_byte_value(id)));
            break;
        }
        case TK_INT16:
        {
            output << std::to_string(data->get_int16_value(id));
            break;
        }
        case TK_INT32:
        {
            output << std::to_string(data->get_int32_value(id));
            break;
        }
        case TK_INT64:
        {
            output << std::to_string(data->get_int64_value(id));
            break;
        }
        case TK_UINT16:
        {
            output << std::to_string(data->get_uint16_value(id));
            break;
        }
        case TK_UINT32:
        {
            output << std::to_string(data->get_uint32_value(id));
            break;
        }
        case TK_UINT64:
        {
            output << std::to_string(data->get_uint64_value(id));
            break;
        }
        case TK_FLOAT32:
        {
            output << std::to_string(data->get_float32_value(id));
            break;
        }
        case TK_FLOAT64:
        {
            output << std::to_string(data->get_float64_value(id));
            break;
        }
        case TK_FLOAT128:
        {
            output << std::to_string(data->get_float128_value(id));
            break;
        }
        case TK_CHAR8:
        {
            output << std::to_string(data->get_char8_value(id));
            break;
        }
        case TK_CHAR16:
        {
            output << std::to_string(data->get_char16_value(id));
            break;
        }
        case TK_STRING8:
        {
            output << data->get_string_value(id);
            break;
        }
        case TK_STRING16:
        {
            std::wcout << data->get_wstring_value(id);
            break;
        }
        case TK_BITMASK:
        {
            size_t size = data->type_->get_size();
            switch (size)
            {
                case 1: output << std::to_string(data->get_uint8_value(id)); break;
                case 2: output << std::to_string(data->get_uint16_value(id)); break;
                case 3: output << std::to_string(data->get_uint32_value(id)); break;
                case 4: output << std::to_string(data->get_uint64_value(id)); break;
            }
            break;
        }
        case TK_ENUM:
        {
            output << std::to_string(data->get_enum_value(id));
            break;
        }
        default:
            break;
    }
}

void DynamicDataHelper::print_collection(
        DynamicData* data,
        const std::string& tabs)
{
    switch (data->type_->get_element_type()->get_kind())
    {
        case TK_NONE:
        case TK_BOOLEAN:
        case TK_BYTE:
        case TK_INT16:
        case TK_INT32:
        case TK_INT64:
        case TK_UINT16:
        case TK_UINT32:
        case TK_UINT64:
        case TK_FLOAT32:
        case TK_FLOAT64:
        case TK_FLOAT128:
        case TK_CHAR8:
        case TK_CHAR16:
        case TK_STRING8:
        case TK_STRING16:
        case TK_ENUM:
        case TK_BITMASK:
        {
            print_basic_collection(data);
            break;
        }
        case TK_STRUCTURE:
        case TK_BITSET:
        case TK_UNION:
        case TK_SEQUENCE:
        case TK_ARRAY:
        case TK_MAP:
        {
            print_complex_collection(data, tabs);
            break;
        }
        default:
            break;

    }
}

void DynamicDataHelper::print_collection(
        DynamicData* data,
        std::ostream& output,
        const std::string& tabs)
{
    switch (data->type_->get_element_type()->get_kind())
    {
        case TK_NONE:
        case TK_BOOLEAN:
        case TK_BYTE:
        case TK_INT16:
        case TK_INT32:
        case TK_INT64:
        case TK_UINT16:
        case TK_UINT32:
        case TK_UINT64:
        case TK_FLOAT32:
        case TK_FLOAT64:
        case TK_FLOAT128:
        case TK_CHAR8:
        case TK_CHAR16:
        case TK_STRING8:
        case TK_STRING16:
        case TK_ENUM:
        case TK_BITMASK:
        {
            print_basic_collection(data, output);
            break;
        }
        case TK_STRUCTURE:
        case TK_BITSET:
        case TK_UNION:
        case TK_SEQUENCE:
        case TK_ARRAY:
        case TK_MAP:
        {
            print_complex_collection(data, output, tabs);
            break;
        }
        default:
            break;

    }
}

void DynamicDataHelper::fill_array_positions(
        const std::vector<uint32_t>& bounds,
        std::vector<std::vector<uint32_t>>& positions)
{
    uint32_t total_size = 1;
    for (size_t i = 0; i < bounds.size(); ++i)
    {
        total_size *= bounds[i];
    }

    for (uint32_t idx = 0; idx < total_size; ++idx)
    {
        positions.push_back({});
        get_index_position(idx, bounds, positions[idx]);
    }
}

void DynamicDataHelper::get_index_position(
        uint32_t index,
        const std::vector<uint32_t>& bounds,
        std::vector<uint32_t>& position)
{
    position.resize(bounds.size());
    if (bounds.size() > 0)
    {
        aux_index_position(index, static_cast<uint32_t>(bounds.size() - 1), bounds, position);
    }
}

void DynamicDataHelper::aux_index_position(
        uint32_t index,
        uint32_t inner_index,
        const std::vector<uint32_t>& bounds,
        std::vector<uint32_t>& position)
{
    uint32_t remainder = index % bounds[inner_index];
    position[inner_index] = remainder;
    if (inner_index > 0)
    {
        aux_index_position(index / bounds[inner_index], inner_index - 1, bounds, position);
    }
}

void DynamicDataHelper::print_basic_collection(
        DynamicData* data)
{
    if (data->type_->get_kind() == TK_SEQUENCE)
    {
        auto count = data->get_item_count();
        std::cout << "[";
        for (uint32_t i = 0; i < count; ++i)
        {
            print_basic_element(data, i, data->type_->get_element_type()->get_kind());
            std::cout << (i == count - 1 ? "]" : ", ");
        }
        if (count == 0)
        {
            std::cout << "]";
        }
    }
    else
    {
        const std::vector<uint32_t>& bounds = data->type_->descriptor_->bound_;

        std::vector<std::vector<uint32_t>> positions;
        fill_array_positions(bounds, positions);

        std::cout << "[";
        for (size_t i = 0; i < positions.size(); ++i)
        {
            print_basic_element(data, data->get_array_index(positions[i]), data->type_->get_element_type()->get_kind());
            std::cout << (i == positions.size() - 1 ? "]" : ", ");
        }
    }
    std::cout << std::endl;
}

void DynamicDataHelper::print_basic_collection(
        DynamicData* data,
        std::ostream& output)
{
    if (data->type_->get_kind() == TK_SEQUENCE)
    {
        auto count = data->get_item_count();
        output << "[";
        for (uint32_t i = 0; i < count; ++i)
        {
            print_basic_element(data, i, data->type_->get_element_type()->get_kind(), output);
            output << (i == count - 1 ? "]" : ", ");
        }
        if (count == 0)
        {
            output << "]";
        }
    }
    else
    {
        const std::vector<uint32_t>& bounds = data->type_->descriptor_->bound_;

        std::vector<std::vector<uint32_t>> positions;
        fill_array_positions(bounds, positions);

        output << "[";
        for (size_t i = 0; i < positions.size(); ++i)
        {
            print_basic_element(data, data->get_array_index(positions[i]),
                    data->type_->get_element_type()->get_kind(), output);
            output << (i == positions.size() - 1 ? "]" : ", ");
        }
    }
    output << "\n";
}

void DynamicDataHelper::print_complex_collection(
        DynamicData* data,
        const std::string& tabs)
{
    std::cout << std::endl;
    if (data->type_->get_kind() == TK_SEQUENCE)
    {
        auto count = data->get_item_count();

        for (uint32_t i = 0; i < count; ++i)
        {
            std::cout << tabs << "[" << i << "] = ";
            print_complex_element(data, i, tabs);
            std::cout << std::endl;
        }

        if (count == 0)
        {
            std::cout << "[]";
        }
    }
    else
    {
        const std::vector<uint32_t>& bounds = data->type_->descriptor_->bound_;

        std::vector<std::vector<uint32_t>> positions;
        fill_array_positions(bounds, positions);

        for (size_t i = 0; i < positions.size(); ++i)
        {
            std::cout << tabs << "[" << i << "] = ";
            print_complex_element(data, data->get_array_index(positions[i]), tabs);
            std::cout << std::endl;
        }
    }
}

void DynamicDataHelper::print_complex_collection(
        DynamicData* data,
        std::ostream& output,
        const std::string& tabs)
{
    output << "\n";
    if (data->type_->get_kind() == TK_SEQUENCE)
    {
        auto count = data->get_item_count();

        for (uint32_t i = 0; i < count; ++i)
        {
            output << tabs;
            output << "[";
            output << std::to_string(i);
            output << "] = ";
            print_complex_element(data, i, output, tabs);
            output << "\n";
        }

        if (count == 0)
        {
            output << "[]";
        }
    }
    else
    {
        const std::vector<uint32_t>& bounds = data->type_->descriptor_->bound_;

        std::vector<std::vector<uint32_t>> positions;
        fill_array_positions(bounds, positions);

        for (size_t i = 0; i < positions.size(); ++i)
        {
            output << tabs;
            output << "[";
            output << std::to_string(i);
            output << "] = ";
            print_complex_element(data, data->get_array_index(positions[i]), output, tabs);
            output << "\n";
        }
    }
}

void DynamicDataHelper::print_complex_element(
        DynamicData* data,
        MemberId id,
        const std::string& tabs)
{
    DynamicData* st_data = data->loan_value(id);
    const TypeDescriptor* desc = st_data->type_->get_type_descriptor();
    switch (desc->get_kind())
    {
        case TK_STRUCTURE:
        case TK_BITSET:
        {
            std::cout << "<struct/bitset>" << std::endl;
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            st_data->type_->get_all_members(members);
            for (auto it : members)
            {
                print_member(st_data, it.second, tabs + "\t");
            }
            break;
        }
        case TK_UNION:
        {
            std::cout << "<union>" << std::endl;
            DynamicTypeMember member;
            st_data->type_->get_member(member, st_data->union_id_);
            print_member(st_data, &member, tabs + "\t");
            break;
        }
        case TK_SEQUENCE:
        case TK_ARRAY:
        {
            print_collection(st_data, tabs + "\t");
            break;
        }
        case TK_MAP:
        {
            std::cout << "<map>" << std::endl;
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            st_data->type_->get_all_members(members);
            size_t size = st_data->get_item_count();
            for (size_t i = 0; i < size; ++i)
            {
                size_t index = i * 2;
                MemberId member_id = st_data->get_member_id_at_index(static_cast<uint32_t>(index));
                std::cout << "Key: ";
                print_member(st_data, members[member_id], tabs + "\t");
                member_id = data->get_member_id_at_index(static_cast<uint32_t>(index + 1));
                std::cout << "Value: ";
                print_member(st_data, members[member_id], tabs + "\t");
            }
            break;
        }
        default:
            break;
    }
    data->return_loaned_value(st_data);
}

void DynamicDataHelper::print_complex_element(
        DynamicData* data,
        MemberId id,
        std::ostream& output,
        const std::string& tabs)
{
    DynamicData* st_data = data->loan_value(id);
    const TypeDescriptor* desc = st_data->type_->get_type_descriptor();
    switch (desc->get_kind())
    {
        case TK_STRUCTURE:
        case TK_BITSET:
        {
            output << "<struct/bitset>\n";
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            st_data->type_->get_all_members(members);
            for (auto it : members)
            {
                print_member(st_data, output, it.second, tabs + "\t");
            }
            break;
        }
        case TK_UNION:
        {
            output << "<union>\n";
            DynamicTypeMember member;
            st_data->type_->get_member(member, st_data->union_id_);
            print_member(st_data, output, &member, tabs + "\t");
            break;
        }
        case TK_SEQUENCE:
        case TK_ARRAY:
        {
            print_collection(st_data, output, tabs + "\t");
            break;
        }
        case TK_MAP:
        {
            output << "<map>\n";
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            st_data->type_->get_all_members(members);
            size_t size = st_data->get_item_count();
            for (size_t i = 0; i < size; ++i)
            {
                size_t index = i * 2;
                MemberId member_id = st_data->get_member_id_at_index(static_cast<uint32_t>(index));
                output << "Key: ";
                print_member(st_data, output, members[member_id], tabs + "\t");
                member_id = data->get_member_id_at_index(static_cast<uint32_t>(index + 1));
                output << "Value: ";
                print_member(st_data, output, members[member_id], tabs + "\t");
            }
            break;
        }
        default:
            break;
    }
    data->return_loaned_value(st_data);
}

void DynamicDataHelper::print_member(
        DynamicData* data,
        const DynamicTypeMember* type,
        const std::string& tabs)
{
    std::cout << tabs << type->get_name() << ": ";
    const MemberDescriptor* desc = type->get_descriptor();
    switch (desc->get_kind())
    {
        case TK_NONE:
        case TK_BOOLEAN:
        case TK_BYTE:
        case TK_INT16:
        case TK_INT32:
        case TK_INT64:
        case TK_UINT16:
        case TK_UINT32:
        case TK_UINT64:
        case TK_FLOAT32:
        case TK_FLOAT64:
        case TK_FLOAT128:
        case TK_CHAR8:
        case TK_CHAR16:
        case TK_STRING8:
        case TK_STRING16:
        case TK_ENUM:
        case TK_BITMASK:
        {
            print_basic_element(data, type->get_id(), desc->get_kind());
            std::cout << std::endl;
            break;
        }
        case TK_STRUCTURE:
        case TK_BITSET:
        {
            DynamicData* st_data = data->loan_value(type->get_id());
            std::cout << "<struct/bitset>" << std::endl;
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            desc->get_type()->get_all_members(members);
            for (auto it : members)
            {
                print_member(st_data, it.second, tabs + "\t");
            }
            data->return_loaned_value(st_data);
            break;
        }
        case TK_UNION:
        {
            std::cout << "<union>" << std::endl;
            DynamicData* st_data = data->loan_value(type->get_id());
            DynamicTypeMember member;
            desc->get_type()->get_member(member, data->union_id_);
            print_member(st_data, &member, tabs + "\t");
            break;
        }
        case TK_SEQUENCE:
        case TK_ARRAY:
        case TK_ALIAS:
        {
            DynamicData* st_data = data->loan_value(type->get_id());
            print_collection(st_data, tabs + "\t");
            data->return_loaned_value(st_data);
            break;
        }
        case TK_MAP:
        {
            std::cout << "<map>" << std::endl;
            DynamicData* st_data = data->loan_value(type->get_id());
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            desc->get_type()->get_all_members(members);
            size_t size = data->get_item_count();
            for (size_t i = 0; i < size; ++i)
            {
                size_t index = i * 2;
                MemberId id = data->get_member_id_at_index(static_cast<uint32_t>(index));
                std::cout << "Key: ";
                print_member(st_data, members[id], tabs + "\t");
                id = data->get_member_id_at_index(static_cast<uint32_t>(index + 1));
                std::cout << "Value: ";
                print_member(st_data, members[id], tabs + "\t");
            }
            data->return_loaned_value(st_data);
            break;
        }
        default:
            break;
    }
}

void DynamicDataHelper::print_member(
        DynamicData* data,
        std::ostream& output,
        const DynamicTypeMember* type,
        const std::string& tabs)
{
    output << tabs;
    output << type->get_name();
    output << ": ";
    const MemberDescriptor* desc = type->get_descriptor();
    switch (desc->get_kind())
    {
        case TK_NONE:
        case TK_BOOLEAN:
        case TK_BYTE:
        case TK_INT16:
        case TK_INT32:
        case TK_INT64:
        case TK_UINT16:
        case TK_UINT32:
        case TK_UINT64:
        case TK_FLOAT32:
        case TK_FLOAT64:
        case TK_FLOAT128:
        case TK_CHAR8:
        case TK_CHAR16:
        case TK_STRING8:
        case TK_STRING16:
        case TK_ENUM:
        case TK_BITMASK:
        {
            print_basic_element(data, type->get_id(), desc->get_kind(), output);
            output << "\n";
            break;
        }
        case TK_STRUCTURE:
        case TK_BITSET:
        {
            DynamicData* st_data = data->loan_value(type->get_id());
            output << "<struct/bitset>\n";
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            desc->get_type()->get_all_members(members);
            for (auto it : members)
            {
                print_member(st_data, output, it.second, tabs + "\t");
            }
            data->return_loaned_value(st_data);
            break;
        }
        case TK_UNION:
        {
            output << "<union>\n";
            DynamicData* st_data = data->loan_value(type->get_id());
            DynamicTypeMember member;
            desc->get_type()->get_member(member, data->union_id_);
            print_member(st_data, output, &member, tabs + "\t");
            break;
        }
        case TK_SEQUENCE:
        case TK_ARRAY:
        {
            DynamicData* st_data = data->loan_value(type->get_id());
            print_collection(st_data, output, tabs + "\t");
            data->return_loaned_value(st_data);
            break;
        }
        case TK_MAP:
        {
            output << "<map>\n";
            DynamicData* st_data = data->loan_value(type->get_id());
            std::map<types::MemberId, types::DynamicTypeMember*> members;
            desc->get_type()->get_all_members(members);
            size_t size = data->get_item_count();
            for (size_t i = 0; i < size; ++i)
            {
                size_t index = i * 2;
                MemberId id = data->get_member_id_at_index(static_cast<uint32_t>(index));
                output << "Key: ";
                print_member(st_data, output, members[id], tabs + "\t");
                id = data->get_member_id_at_index(static_cast<uint32_t>(index + 1));
                output << "Value: ";
                print_member(st_data, output, members[id], tabs + "\t");
            }
            data->return_loaned_value(st_data);
            break;
        }
        default:
            break;
    }
}
